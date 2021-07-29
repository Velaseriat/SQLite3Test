// Fill out your copyright notice in the Description page of Project Settings.


#include "DataStorageWrapper.h"
#include "Misc/Paths.h"

bool UDataStorageWrapper::ImportDLL(FString a_strFolderName, FString a_strDLLName)
{
	FString filePath = *FPaths::ProjectPluginsDir() + a_strFolderName + "/" + a_strDLLName;
	if (FPaths::FileExists(filePath))
	{
		v_dllHandle = FPlatformProcess::GetDllHandle(*filePath); // Retrieve the DLL.
		if (v_dllHandle != NULL)
		{
			return true;
		}
	}
	return false;// Return an error.
}

bool UDataStorageWrapper::ImportMethod_Sqlite3_LibVersion()
{
	if (v_dllHandle != NULL)
	{
		m_funcSqlite3_libversion = NULL;
		FString procName = "sqlite3_libversion_number";// Needs to be the exact name of the DLL method.
		m_funcSqlite3_libversion = (sqlite3_libversion)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_funcSqlite3_libversion != NULL)
		{
			return true;
		}
	}
	return false;// Return an error.
}

int UDataStorageWrapper::CallSqlite3_LibVersion()
{
	if (m_funcSqlite3_libversion == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("OPS Client Function was null"));
		return INT_MIN;
	}
	int version = m_funcSqlite3_libversion();
	UE_LOG(LogTemp, Error, TEXT("Lib version number is: %d"), version);
	return version;
}
