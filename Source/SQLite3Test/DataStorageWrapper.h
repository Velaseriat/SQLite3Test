// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
 
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataStorageWrapper.generated.h"
/**
&nbsp;*
&nbsp;*/
 
typedef int(*sqlite3_libversion)(void);
 
UCLASS()
class SQLITE3TEST_API UDataStorageWrapper : public UObject
{
GENERATED_BODY()
private:
void *v_dllHandle;
sqlite3_libversion m_funcSqlite3_libversion;
 
public:
UFUNCTION(BlueprintCallable, Category = "CPP Utilitites")
bool ImportDLL(FString a_strFolderName, FString a_strDLLName);
 
UFUNCTION(BlueprintCallable, Category = "CPP Utilitites")
bool ImportMethod_Sqlite3_LibVersion();
 
UFUNCTION(BlueprintCallable, Category = "CPP Utilitites")
int CallSqlite3_LibVersion();
};
