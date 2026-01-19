#include "Moving.h"
#include "UObject/ConstructorHelpers.h"

AMoving::AMoving()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 200.f;
	MaxRange = 300.f;

	MoveDirection = FVector(1.f, 0.f, 0.f);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/UtopianCity/Meshes/SM_FountainMiddle.SM_FountainMiddle")
	);
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
}

void AMoving::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMoving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector DeltaMove = MoveDirection * MoveSpeed * DeltaTime;
	AddActorWorldOffset(DeltaMove);

	float Distance = FVector::Dist(StartLocation, GetActorLocation());

	if (Distance >= MaxRange)
	{
		MoveDirection *= -1.f;
	}
}