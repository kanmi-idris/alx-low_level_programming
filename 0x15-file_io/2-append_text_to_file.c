#include <stdio.h>
#include <stdlib.h>

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *fp;
	int ret = -1;

	if (filename == NULL)
	{
		return ret;
	}

	if (text_content == NULL)
	{
		fp = fopen(filename, "a");
		if (fp != NULL)
		{
			fclose(fp);
			ret = 1;
		}
	}
	else
	{
		fp = fopen(filename, "a+");
		if (fp != NULL)
		{
			fputs(text_content, fp);
			fputs("\n", fp);
			fclose(fp);
			ret = 1;
		}
	}

	return ret;
}
