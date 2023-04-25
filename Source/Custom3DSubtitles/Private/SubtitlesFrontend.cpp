// Copyright 2023 Gabriel Bustillo del Cuvillo


#include "SubtitlesFrontend.h"

USubtitlesFrontend::USubtitlesFrontend(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer)
{
//    SubtitleFinishedDelegate.AddUObject(this,"PassSubtitles");
}

void USubtitlesFrontend::SubtitlesFinished()
{
    SubtitleFinishedDelegate.Broadcast();
}

