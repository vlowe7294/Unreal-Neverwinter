// Fill out your copyright notice in the Description page of Project Settings.

#include "NWNDoor.h"


// Sets default values
ANWNDoor::ANWNDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_rotDeg = 0.0f;
}

// Called when the game starts or when spawned
void ANWNDoor::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(false);
	m_rotation = GetActorRotation();	
}

// Called every frame
void ANWNDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_rotDeg += 1.0;

	if (m_rotDeg > 80.0)
	{
		SetActorTickEnabled(false);
	}

	m_rotation.Yaw += 1.0;
	SetActorRotation(m_rotation);
}

void ANWNDoor::OnUsed()
{
	if (m_rotDeg < 80.0)
	{
		SetActorTickEnabled(true);
	}

}

