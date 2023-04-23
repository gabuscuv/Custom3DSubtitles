// Fill out your copyright notice in the Description page of Project Settings.


#include "SubtitlesFrontend.h"

USubtitlesFrontend::USubtitlesFrontend(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer)
{
//    SubtitleFinishedDelegate.AddUObject(this,"PassSubtitles");
}

void USubtitlesFrontend::SubtitlesFinished()
{
    SubtitleFinishedDelegate.Broadcast();
}

