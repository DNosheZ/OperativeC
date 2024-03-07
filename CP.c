#include <windows.h>
#include <stdio.h>

void main(int argc, char* argv[]){	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb - sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
		
	if(!CreateProcess(NULL,	
		"C:\\Windows\\System32\\calc.exe",
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi))
	{
		printf("Fallo CreateProcess() (%d).\n", GetLastError());
		return;
	}
	//Esperar hasta que proceso hijo termine.
	WaitForSingleObject(pi.hProcess, INFINITE);
	// Terminar proceso padre y cerrar manejadores
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

}