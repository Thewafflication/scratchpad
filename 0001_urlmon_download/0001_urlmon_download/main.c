#include <stdio.h>
#include <urlmon.h>
#include <windows.h>

#pragma comment(lib, "urlmon.lib")

int main(int argc, char** argv)
{
	HRESULT hr = NULL;
	char *url = NULL;
	char *fn = NULL;
	HMODULE hUrlmon;

	if(argc < 2 || argc > 3)
	{
		printf("Usage: 0001_urlmon_download.exe <url> [filename]\n");
		return -1;
	}

	url = argv[1];
	fn = (argc == 3) ? argv[2] : "output.file";

	printf("Attempting to download %s from %s\n", fn, url);

	hr = URLDownloadToFileA(NULL, url, fn, 0, NULL);
	hUrlmon = GetModuleHandleA("urlmon.dll");

	if(FAILED(hr))
	{
		char *msg = NULL;
		FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_HMODULE |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			hUrlmon,
			hr,
			0,
			(LPSTR)&msg,
			0,
			NULL
			);
		printf("Download failed...\n0x%08lX\n%s\n", 
			(unsigned long)hr, 
			msg ? msg : "Unknown error"
			);
		if(msg)
			LocalFree(msg);
		return -1;
	}
	return 0;
}