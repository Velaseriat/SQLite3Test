// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

bool UMyGameInstance::ImportDataStorageLibrary()
{
    //create the wrapper object
    m_refDataStorageWrapper = NewObject<UDataStorageWrapper>(this);
    if (m_refDataStorageWrapper == NULL)
    {
        UE_LOG(LogTemp, Error, TEXT("Could not create the Data Storage Object"));
        return false;
    }

    //Import the DLL
    if (!m_refDataStorageWrapper->ImportDLL("DataStorage", "sqlite3.dll"))
    {
        UE_LOG(LogTemp, Error, TEXT("Could not import the Data Storage DLL"));
        return false;
    }
    if (!m_refDataStorageWrapper->ImportMethod_Sqlite3_LibVersion())
    {
        UE_LOG(LogTemp, Error, TEXT("Could not import the sqlite3_libversion Method from the Data Storage Library"));
        return false;
    }
    return true;
}

void UMyGameInstance::Init()
{
    Super::Init();
    if (ImportDataStorageLibrary()) {
        UE_LOG(LogTemp, Log, TEXT("Successfully loaded sqlite3 library (version %d)"), m_refDataStorageWrapper->CallSqlite3_LibVersion());
    }
}
