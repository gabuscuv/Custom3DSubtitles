// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
//#include "Widgets/SubtitlesFrontend.h"
#include "Interfaces/SubtitleFrontend.h"
#include "SubtitlesFrontend.generated.h"
/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FSubtitlesPassDelegate)

UCLASS()
class CUSTOM3DSUBTITLES_API USubtitlesFrontend : public UUserWidget, public ISubtitleFrontendInterface
{
	GENERATED_BODY()
	USubtitlesFrontend(const FObjectInitializer & ObjectInitializer);

	FSubtitlesPassDelegate  SubtitleFinishedDelegate;
	protected:
	UPROPERTY(BlueprintReadWrite)
	FText TextOnScreen;
	UFUNCTION(BlueprintCallable)
	void SubtitlesFinished();

public:
	FORCEINLINE FSubtitlesPassDelegate* GetDelegate() {return &SubtitleFinishedDelegate;}
};
