// Fill out your copyright notice in the Description page of Project Settings.

#include "SimMotionController.h"
#include "SimMotionCharacter.h"


// Sets default values
ASimMotionCharacter::ASimMotionCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimMotionCharacter::BeginPlay()
{
	Super::BeginPlay();

	MotionController = this->FindComponentByClass<USimulatedMotionController>();
	
}

// Called every frame
void ASimMotionCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void ASimMotionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UE_LOG(LogTemp, Warning, TEXT("Pressed button to move left."));
	// Binds all of the motion controller toggles to the functions that will allow the movement and rotation to be set.
	InputComponent->BindAction("MoveMotionControllerLeft", IE_Pressed, this, &ASimMotionCharacter::ToggleMotionLeft);
	InputComponent->BindAction("MoveMotionControllerLeft", IE_Released, this, &ASimMotionCharacter::ToggleMotionLeft);

	InputComponent->BindAction("MoveMotionControllerRight", IE_Pressed, this, &ASimMotionCharacter::ToggleMotionRight);
	InputComponent->BindAction("MoveMotionControllerRight", IE_Released, this, &ASimMotionCharacter::ToggleMotionRight);

	InputComponent->BindAction("MoveMotionControllerForward", IE_Pressed, this, &ASimMotionCharacter::ToggleMotionForward);
	InputComponent->BindAction("MoveMotionControllerForward", IE_Released, this, &ASimMotionCharacter::ToggleMotionForward);

	InputComponent->BindAction("MoveMotionControllerBack", IE_Pressed, this, &ASimMotionCharacter::ToggleMotionBack);
	InputComponent->BindAction("MoveMotionControllerBack", IE_Released, this, &ASimMotionCharacter::ToggleMotionBack);

	InputComponent->BindAction("MoveMotionControllerUp", IE_Pressed, this, &ASimMotionCharacter::ToggleMotionUp);
	InputComponent->BindAction("MoveMotionControllerUp", IE_Released, this, &ASimMotionCharacter::ToggleMotionUp);

	InputComponent->BindAction("MoveMotionControllerDown", IE_Pressed, this, &ASimMotionCharacter::ToggleMotionDown);
	InputComponent->BindAction("MoveMotionControllerDown", IE_Released, this, &ASimMotionCharacter::ToggleMotionDown);

	InputComponent->BindAction("RotateControllerAroundX", IE_Pressed, this, &ASimMotionCharacter::ToggleXRotation);
	InputComponent->BindAction("RotateControllerAroundX", IE_Released, this, &ASimMotionCharacter::ToggleXRotation);

	InputComponent->BindAction("RotateControllerAroundY", IE_Pressed, this, &ASimMotionCharacter::ToggleYRotation);
	InputComponent->BindAction("RotateControllerAroundY", IE_Released, this, &ASimMotionCharacter::ToggleYRotation);

	InputComponent->BindAction("RotateControllerAroundZ", IE_Pressed, this, &ASimMotionCharacter::ToggleZRotation);
	InputComponent->BindAction("RotateControllerAroundZ", IE_Released, this, &ASimMotionCharacter::ToggleZRotation);


}

void ASimMotionCharacter::ToggleXRotation()
{
	MotionController->ToggleXRotation();
}

void ASimMotionCharacter::ToggleYRotation()
{
	MotionController->ToggleYRotation();
}

void ASimMotionCharacter::ToggleZRotation()
{
	MotionController->ToggleZRotation();
}

void ASimMotionCharacter::ToggleMotionLeft()
{
	MotionController->ToggleMoveLeft();
}

void ASimMotionCharacter::ToggleMotionRight()
{
	MotionController->ToggleMoveRight();
}

void ASimMotionCharacter::ToggleMotionForward()
{
	MotionController->ToggleMoveForward();
}

void ASimMotionCharacter::ToggleMotionBack()
{
	MotionController->ToggleMoveBack();
}

void ASimMotionCharacter::ToggleMotionUp()
{
	MotionController->ToggleMoveUp();
}

void ASimMotionCharacter::ToggleMotionDown()
{
	MotionController->ToggleMoveDown();
}
