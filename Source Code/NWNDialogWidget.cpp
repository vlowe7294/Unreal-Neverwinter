// Fill out your copyright notice in the Description page of Project Settings.

#include "NWNDialogWidget.h"

NWNException::NWNException(FString msg)
{

}

NWNException::~NWNException()
{

}



void UNWNDialogWidget::Init()
{
	m_startIndx = 0;
	Load();
}

FString ReadString(IFileHandle* fle)
{
	unsigned char len = 0;
	char buf[255];
	FString retStr;

	if (fle == NULL)
		return retStr;

	uint8* ByteBuffer = reinterpret_cast<uint8*>(&len);
	fle->Read(ByteBuffer, 1);

	if (len > 250)
		throw new NWNException("String length exceeded");

	ByteBuffer = reinterpret_cast<uint8*>(buf);
	fle->Read(ByteBuffer, len);
	buf[len] = 0;
	retStr = buf;	

	return retStr;
}

void UNWNDialogWidget::Load()
{
	try
	{
		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		FString AbsoluteFilePath = "D:/Documents/conversations.dat";
		IFileHandle* FileHandle = PlatformFile.OpenRead(*AbsoluteFilePath);
		FLINE newLine;

		m_lineList.Empty();	

		if (FileHandle)
		{
			m_name = ReadString(FileHandle);
			ReadLine(newLine, FileHandle);
			m_startIndx = newLine.indx;
			delete FileHandle;
		}
		else
			throw new NWNException("Unable to open data file" + AbsoluteFilePath);
		
	}
	catch (NWNException* exc)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Exception: UNWNDialogWidget::Load()")));
		delete exc;
	}

}

void UNWNDialogWidget::ReadLine(FLINE& ln, IFileHandle* fle)
{
	int id = 0;

	ClearLine(ln);
	FLINE* pNwLine;

	ln.text = ReadString(fle);
	id = ln.indx = m_lineList.Num();
	uint8* ByteBuffer = reinterpret_cast<uint8*>(&ln.nReplies);

	fle->Read(ByteBuffer, 4);	
	m_lineList.Add(ln);

	for (int i = 0; i < ln.nReplies; i++)
	{
		pNwLine = new FLINE();
		ReadLine(*pNwLine, fle);
		m_lineList[id].replies.Add(pNwLine->indx);

		delete pNwLine;
	}

}

void UNWNDialogWidget::ClearLine(FLINE& ln)
{
	ln.replies.Empty();
	ln.nReplies = 0;
}

void UNWNDialogWidget::GetLine(FLINE& ln, int ndx)
{
	if (ndx >= m_lineList.Num())
		return;

	ln = m_lineList[ndx];
	FString msg = FString::Printf(TEXT("Function: UNWNDialogWidget::GetLine() Line gotten: ln.nReplies = %d"), ln.nReplies);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, msg);


}




