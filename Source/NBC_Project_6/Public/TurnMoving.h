// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurnMoving.generated.h"

UCLASS()
class NBC_PROJECT_6_API ATurnMoving : public AActor
{
	GENERATED_BODY()

public:
	ATurnMoving();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;

private:
	FVector StartLocation;
	int32 MoveDirection = 1;

public:
	// ===== 이동 =====
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MoveSpeed = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MaxRange = 300.0f;

	// ===== 회전 (Roll) =====
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate")
	float RollSpeed = 180.0f;
};
