// Gabriel Bustillo del Cuvillo

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include <AdvancedSubtitleCue.h>
#include "SubtitleExecute.generated.h"

struct FSubtitleCue;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USubtitleExecute : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CUSTOM3DSUBTITLES_API ISubtitleExecute
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Subtitles")
	void PushSubtitles( const TArray<FAdvancedSubtitleCue>& subtitles);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Subtitles")
	void PassSubtitles();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Subtitles")
	void ChangeArmSpring(bool enable);
};
