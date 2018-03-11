// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NWNDoor.generated.h"

UCLASS()
class RAVENLOFT_API ANWNDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANWNDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Door Functions")
	void OnUsed();

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Name"))
	FString m_name;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Tag"))
	FString m_tag;

private:
	FRotator m_rotation;
	float m_rotDeg;
	
};
