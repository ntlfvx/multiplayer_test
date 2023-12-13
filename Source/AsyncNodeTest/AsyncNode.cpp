// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncNode.h"
#include "BaseTargetActor.h"

UAsyncNode* UAsyncNode::WaitForBooleanChange(UObject* WorldContextObject, AActor* ListenActor, ABaseTargetActor* TargetActor)
{
	UAsyncNode* Action = NewObject<UAsyncNode>();
	Action->ListeningActor = ListenActor;
	Action->TargetActor = TargetActor;
	return Action;
}

void UAsyncNode::Activate()
{
	if (TargetActor && ListeningActor)
	{
		TargetActor->OnBooleanValueChanged.AddDynamic(this, &UAsyncNode::OnBooleanValueChanged);
	}
}

void UAsyncNode::OnBooleanValueChanged(const bool NewValue)
{
	OnValueChanged.Broadcast(NewValue);
}