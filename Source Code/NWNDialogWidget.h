// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlatformFilemanager.h"
#include "NWNDialogWidget.generated.h"

class NWNException
{
public:
	NWNException(FString msg);
	~NWNException();
};

USTRUCT(BlueprintType)
struct FLINE
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FString text;

	UPROPERTY(BlueprintReadOnly)
	int nReplies;

	UPROPERTY(BlueprintReadOnly)
	TArray<int> replies;

	int indx;
};

/**
 * 
 */
UCLASS()
class EYE_OF_THE_BEHOLDER_API UNWNDialogWidget : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Dialog Functions")
	void Init();

	UFUNCTION(BlueprintCallable, Category = "Dialog Functions")
	void GetLine(FLINE& ln, int ndx);

private:
	int m_startIndx;
	TArray<FLINE> m_lineList;
	FString m_name;

	void Load();
	void ReadLine(FLINE& ln, IFileHandle* fle);
	void ClearLine(FLINE& ln);
	
};
