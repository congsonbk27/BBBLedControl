/*
 ============================================================================
 Name        : w7d1_control_led.c
 Author      : congson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flash(char *led, char *time_ms) {
	char * ledPath;
	ledPath = (char *)calloc(50, sizeof(char));
	if (strcmp(led, "led0") == 0) {
		strcpy(ledPath, "sys/class/leds/beaglebone:green:usr0/"); ///brightness");
	} else if (strcmp(led, "led1") == 0) {
		strcpy(ledPath, "sys/class/leds/beaglebone:green:usr1/"); //brightness");
	} else if (strcmp(led, "led2") == 0) {
		strcpy(ledPath, "sys/class/leds/beaglebone:green:usr2/"); //brightness");
	} else if (strcmp(led, "led3") == 0) {
		strcpy(ledPath, "sys/class/leds/beaglebone:green:usr3/"); //brightness");
	} else {
		printf("led input wrong\n");
		return EXIT_FAILURE;
	}
	FILE *fp;
	char check;

	/*===== write "NONE" into trigger ======================================*/
	char * triggerPath;
	triggerPath = (char *)calloc(50, sizeof(char));
	sprintf(triggerPath, "%strigger", ledPath);
	fp = fopen(triggerPath, "w+"); 						/* easer and write */
	if (!fp) {
		printf("can not open %s\n", triggerPath);
		return EXIT_FAILURE;
	}
	check = fputs("none", fp);
	if (check == EOF) {
		printf("can not write file trigger\n");
		fclose(fp);
		return EXIT_FAILURE;
	}
	fclose(fp);
	printf("write file trigger OK\n");
	/*===== end write "NONE" into trigger ====================================*/

	/*=====  write "time_ms" into delay_on ===================================*/
	char * delayOnPath;
	delayOnPath = (char *)calloc(50, sizeof(char));
	sprintf(delayOnPath, "%sdelay_on", ledPath);
	fp = fopen(delayOnPath, "w+"); 							/* easer and write */
	if (!fp) {
		printf("can not open %s\n", delayOnPath);
		return EXIT_FAILURE;
	}
	check = fputs(time_ms, fp);
	if (check == EOF) {
		printf("can not write file delay_on\n");
		fclose(fp);
		return EXIT_FAILURE;
	}
	fclose(fp);
	printf("write file delay_on OK\n");
	/*===== end write "time_ms" into delay_on ================================*/

	/*=====  write "time_ms" into delay_off ===================================*/
	char * delayOffPath;
	delayOffPath = (char *)calloc(50, sizeof(char));
	sprintf(delayOffPath, "%sdelay_off", ledPath);
	fp = fopen(delayOffPath, "w+"); 						/* easer and write */
	if (!fp) {
		printf("can not open %s\n", delayOffPath);
		return EXIT_FAILURE;
	}
	check = fputs(time_ms, fp);
	if (check == EOF) {
		printf("can not write file delay_off\n");
		fclose(fp);
		return EXIT_FAILURE;
	}
	fclose(fp);
	printf("write file ddelay_off OK\n");
	/*===== end write "time_ms" into delay_off ================================*/
	return EXIT_SUCCESS;
}

int brightness(char *led, char *status) {
	char * ledPath;
	ledPath = (char *)calloc(50, sizeof(char));
	if (strcmp(led, "led0") == 0) {
		strcpy(ledPath, "sys/class/leds/beaglebone:green:usr0/brightness");
	} else if (strcmp(led, "led1") == 0) {
		strcpy(ledPath, "sys/class/leds/beaglebone:green:usr1/brightness");
	} else if (strcmp(led, "led2") == 0) {
		strcpy(ledPath, "sys/class/leds/beaglebone:green:usr2/brightness");
	} else if (strcmp(led, "led3") == 0) {
		strcpy(ledPath, "sys/class/leds/beaglebone:green:usr3/brightness");
	} else {
		printf("led input wrong\n");
		return EXIT_FAILURE;
	}
	if ((strcmp(status, "0") != 0) && (strcmp(status, "1") != 0)) {
		printf("status wrong\n");
		return EXIT_FAILURE;
	}
	FILE *fp;
	fp = fopen(ledPath, "w+"); /* easer and write */
	if (!fp) {
		printf("can not open %s\n", ledPath);
		return EXIT_FAILURE;
	}
	char check;
	check = fputs(status, fp);
	if (check == EOF) {
		printf("can not write file brightness\n");
		fclose(fp);
		return EXIT_FAILURE;
	}
	printf("write file OK\n");
	fclose(fp);
	return EXIT_SUCCESS;
}

/*
 system("rm -r sys");
 system("mkdir sys");
 system("mkdir sys/class");
 system("mkdir sys/class/leds");
 system("mkdir sys/class/leds/beaglebone:green:usr3");
 */
int main(int argc, char **argv) {
	puts("!!!------- Giai bai tap w7d1: Bai 2 -------!!!\n");
	puts("!!!---------- Dieu khien 4 Led  --------!!!\n");
	printf("argc = %d\n", argc);
	printf("argv[0] = %s\n", argv[0]);
	printf("argv[1] = %s\n", argv[1]);
	printf("argv[2] = %s\n", argv[2]);
	printf("argv[3] = %s\n", argv[3]);


	if (strcmp(argv[2], "brightness") == 0) {
		printf("brightness %s %s\n", argv[1], argv[3]);
		brightness(argv[1], argv[3]);
	} else if (strcmp(argv[2], "flash") == 0) {
		printf("flash  %s\n", argv[1]);
		flash(argv[1], argv[3]);
	} else {
		printf("no thing to do\n");
	}
	return EXIT_SUCCESS;
}
