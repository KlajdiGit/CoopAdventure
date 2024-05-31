#include "WinArea.h"
#include "CoopAdventureCharacter.h"

AWinArea::AWinArea()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	WinAreaBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WinAreaBox"));
	SetRootComponent(WinAreaBox);

	WinCondition = false;
}

void AWinArea::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWinArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		if (!WinCondition)
		{
			TArray<AActor*> OverlapActors;
			WinAreaBox->GetOverlappingActors(OverlapActors, ACoopAdventureCharacter::StaticClass());

			WinCondition = (OverlapActors.Num() == 2);
			if (WinCondition)
			{
				UE_LOG(LogTemp, Display, TEXT("WIN!!!"));
			}
		}
	}
}

