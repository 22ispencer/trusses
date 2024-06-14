#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

int main()
{
	FILE *fp = fopen("example.json", "r");
	fseek(fp, 0L, SEEK_END);
	size_t size = ftell(fp);
	rewind(fp);

	char *buf = malloc(size);
	fread(buf, sizeof(buf), size, fp);
	fclose(fp);

	cJSON *json = cJSON_ParseWithLength(buf, size);
	if (json == NULL) {
		printf("Unable to parse JSON");
		return 1;
	}

	cJSON *message_json = cJSON_GetObjectItem(json, "message");
	if (message_json != NULL) {
		printf("message: %s", message_json->valuestring);
	}

	free(buf);
	cJSON_Delete(json);

	return 0;
}
