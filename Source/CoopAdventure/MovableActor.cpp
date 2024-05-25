

#include "MovableActor.h"

AMovableActor::AMovableActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMovableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMovableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

