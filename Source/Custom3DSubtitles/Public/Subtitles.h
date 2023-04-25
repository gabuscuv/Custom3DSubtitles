// Copyright 2023 Gabriel Bustillo del Cuvillo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/WidgetComponent.h"
#include "Interfaces/SubtitleExecute.h"
#include <AdvancedSubtitleCue.h>
#include "Subtitles.generated.h"

struct FSubtitleCue;

//DECLARE_MULTICAST_DELEGATE_OneParam(FSubtitlesPushDelegate,TArray<FSubtitleCue>)
UCLASS()
class ASubtitles : public AActor, public ISubtitleExecute
{
	GENERATED_BODY()
	
private:
// FSubtitlesPassDelegate SubtitlesPassDelegate; 
TArray<FAdvancedSubtitleCue> SubtitlesQueue;
bool isPushingSubtitles = false;
public:	
	// Sets default values for this actor's properties
	ASubtitles();

protected:
		UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USpringArmComponent* SpringArm;
		UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UWidgetComponent*	SubtitlesFrontend;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Subtitles")
	void PushSubtitles(const TArray<FAdvancedSubtitleCue>& subtitles);
	virtual void PushSubtitles_Implementation(const TArray<FAdvancedSubtitleCue>& subtitles) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Subtitles")
	void PassSubtitles();
	virtual void PassSubtitles_Implementation() override;

};
