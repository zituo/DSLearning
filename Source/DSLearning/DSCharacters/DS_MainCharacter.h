// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DS_MainCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class DSLEARNING_API ADS_MainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADS_MainCharacter();

protected:

	// CameraComponent
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* camera;

	// CameraSpringArm
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* springArm;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);

	void MoveRight(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};