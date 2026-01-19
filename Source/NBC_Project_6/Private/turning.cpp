#include "turning.h"
#include "UObject/ConstructorHelpers.h"

Aturning::Aturning()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = 30.0f;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Game/UtopianCity/Meshes/SM_BeamConcrete4m.SM_BeamConcrete4m")
	);
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
}

void Aturning::BeginPlay()
{
	Super::BeginPlay();
}

void Aturning::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(
		FRotator(0.f, RotationSpeed * DeltaTime, 0.f)
	);
}