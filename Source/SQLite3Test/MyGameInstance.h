// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SQLite3Test/DataStorageWrapper.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SQLITE3TEST_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
private:
	UPROPERTY()
	UDataStorageWrapper* m_refDataStorageWrapper;
	bool ImportDataStorageLibrary();
public:
	virtual void Init() override;
};
