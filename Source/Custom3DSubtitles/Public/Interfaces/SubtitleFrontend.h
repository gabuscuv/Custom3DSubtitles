// Gabriel Bustillo del Cuvillo

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include <AdvancedSubtitleCue.h>
#include "SubtitleFrontend.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USubtitleFrontendInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CUSTOM3DSUBTITLES_API ISubtitleFrontendInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void ShowSubtitle(FAdvancedSubtitleCue subtitle);
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void SetSubtitleOffsetSize(float offset);
	//struct FSubtitlesPassDelegate* GetDelegate();
};
