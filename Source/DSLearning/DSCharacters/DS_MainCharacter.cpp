// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_MainCharacter.h"
#include "Camera\CameraComponent.h"
#include "GameFramework\SpringArmComponent.h"

// Sets default values
ADS_MainCharacter::ADS_MainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	springArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");

	springArm->SetupAttachment(RootComponent);

	camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	camera->SetupAttachment(springArm);
}

// Called when the game starts or when spawned
void ADS_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADS_MainCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ADS_MainCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

// Called every frame
void ADS_MainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADS_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ADS_MainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADS_MainCharacter::MoveRight);
}

