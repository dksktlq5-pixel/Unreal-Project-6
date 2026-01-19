#include "TurnMoving.h"

ATurnMoving::ATurnMoving()
{
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube")
	);
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/UtopianCity/Materials/MI_ColoredGlass04.MI_ColoredGlass04"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}

void ATurnMoving::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void ATurnMoving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* ========== 앞뒤 왕복 이동 (X축) ========== */

	FVector CurrentLocation = GetActorLocation();
	float Distance = CurrentLocation.X - StartLocation.X;

	if (FMath::Abs(Distance) >= MaxRange)
	{
		MoveDirection *= -1;
	}

	CurrentLocation.X += MoveDirection * MoveSpeed * DeltaTime;
	SetActorLocation(CurrentLocation);

	/* ========== Roll 회전 ========== */

	if (!FMath::IsNearlyZero(RollSpeed))
	{
		AddActorLocalRotation(
			FRotator(0.0f, 0.0f, RollSpeed * DeltaTime)
		);
	}
}
