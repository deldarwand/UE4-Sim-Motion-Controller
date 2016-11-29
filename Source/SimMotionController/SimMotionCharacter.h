// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "SimulatedMotionController.h"
#include "SimMotionCharacter.generated.h"

UCLASS()
class SIMMOTIONCONTROLLER_API ASimMotionCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASimMotionCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// These are the set of functions which set the controller's moving booleans.
	void ToggleMotionLeft();
	void ToggleMotionRight();
	void ToggleMotionForward();
	void ToggleMotionBack();
	void ToggleMotionUp();
	void ToggleMotionDown();
	void ToggleXRotation();
	void ToggleYRotation();
	void ToggleZRotation();

private:
	/** This is the controller we are going to move and rotate.
	    We get it during the BeginPlay function. */
	USimulatedMotionController* MotionController;
	
};
