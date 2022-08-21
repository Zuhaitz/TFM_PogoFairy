// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < amountEnemies; i++)
	{
		int spawnPointIndex = i;
		int spawnIndexBp = FMath::RandRange(0, blueprintsToSpawn.Num() - 1);

		if (amountEnemies > spawnPointsEnemies.Num())
		{
			UE_LOG(LogTemp, Warning, TEXT("The are more enemies than spawnerPoints "));
			return;	//Secury of crash	
		}

		AActor* spawnPointEnemy = spawnPointsEnemies[spawnPointIndex];
		TSubclassOf<AActor> blueprintToSpawn = blueprintsToSpawn[spawnIndexBp];
		GetWorld()->SpawnActor<AActor>(blueprintToSpawn, spawnPointEnemy->GetTransform());
	}
	
}


