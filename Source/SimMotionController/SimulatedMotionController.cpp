// Fill out your copyright notice in the Description page of Project Settings.

#include "SimMotionController.h"
#include "SimulatedMotionController.h"


USimulatedMotionController::USimulatedMotionController()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.TickGroup = TG_PrePhysics;

	PlayerIndex = 0;
	Hand = EControllerHand::Left;
	bDisableLowLatencyUpdate = false;
	ShouldMoveLeft = ShouldMoveRight = ShouldMoveForward = ShouldMoveBack = ShouldMoveUp = ShouldMoveDown = false;
	ShouldRotateAroundX = ShouldRotateAroundY = ShouldRotateAroundZ = false;
	TranslationSpeedVector = FVector(50.0f);

	/** Change this position when using anywhere else.
	    This is only used as an offset to see in this demo.
	    Controllers should always start at (0,0,0) and move from there.*/
	ControllerPosition = FVector(200.0f, 0.0f, 0.0f);
	ControllerOrientation = FRotator(0.0f);
	RotationSpeedRotator = FRotator(50.0f, 50.0f, 50.0f);

}

void USimulatedMotionController::BeginPlay()
{
	
}

void USimulatedMotionController::ToggleMoveLeft()
{
	ShouldMoveLeft = !ShouldMoveLeft;
}

void USimulatedMotionController::ToggleMoveRight()
{
	ShouldMoveRight = !ShouldMoveRight;
}

void USimulatedMotionController::ToggleMoveForward()
{
	ShouldMoveForward = !ShouldMoveForward;
}

void USimulatedMotionController::ToggleMoveBack()
{
	ShouldMoveBack = !ShouldMoveBack;
}

void USimulatedMotionController::ToggleMoveUp()
{
	ShouldMoveUp = !ShouldMoveUp;
}

void USimulatedMotionController::ToggleMoveDown()
{
	ShouldMoveDown = !ShouldMoveDown;
}

void USimulatedMotionController::TranslateController(FVector TranslationVector)
{
	ControllerPosition += TranslationVector;
}

void USimulatedMotionController::ToggleXRotation()
{
	ShouldRotateAroundX = !ShouldRotateAroundX;
}

void USimulatedMotionController::ToggleYRotation()
{
	ShouldRotateAroundY = !ShouldRotateAroundY;
}

void USimulatedMotionController::ToggleZRotation()
{
	ShouldRotateAroundZ = !ShouldRotateAroundZ;
}

void USimulatedMotionController::RotateController(FRotator RotationRotator)
{
	ControllerOrientation += RotationRotator;
}

bool USimulatedMotionController::PollControllerState(FVector& Position, FRotator& Orientation)
{
	Position = ControllerPosition;
	Orientation = ControllerOrientation;
	return true;
}

void USimulatedMotionController::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (!ShouldBeSimulated)
	{
		UMotionControllerComponent::TickComponent(DeltaTime, TickType, ThisTickFunction);
		return;
	}
	FVector Position = FVector(0.0f);
	FRotator Orientation;
	FVector DeltaMovement = TranslationSpeedVector * DeltaTime;
	FRotator DeltaRotation = RotationSpeedRotator* DeltaTime;
	FVector TranslationVector = FVector(0.0f);

	if (ShouldMoveLeft)
	{
		TranslationVector.Y -= DeltaMovement.Y;
	}
	if (ShouldMoveRight)
	{
		TranslationVector.Y += DeltaMovement.Y;
	}
	if (ShouldMoveForward)
	{
		TranslationVector.X += DeltaMovement.X;
	}
	if (ShouldMoveBack)
	{
		TranslationVector.X -= DeltaMovement.X;
	}
	if (ShouldMoveDown)
	{
		TranslationVector.Z -= DeltaMovement.Z;
	}
	if (ShouldMoveUp)
	{
		TranslationVector.Z += DeltaMovement.Z;
	}

	FRotator RotationRotator = FRotator(0.0f);
	if (ShouldRotateAroundX)
	{
		RotationRotator.Roll += DeltaRotation.Roll;
	}
	if (ShouldRotateAroundY)
	{
		RotationRotator.Pitch += DeltaRotation.Pitch;
	}
	if (ShouldRotateAroundZ)
	{
		RotationRotator.Yaw += DeltaRotation.Yaw;
	}

	RotateController(RotationRotator);
	TranslateController(TranslationVector);

	bool bTracked = PollControllerState(Position, Orientation);
	if (bTracked)
	{
		SetRelativeLocationAndRotation(Position, Orientation);
	}
}


