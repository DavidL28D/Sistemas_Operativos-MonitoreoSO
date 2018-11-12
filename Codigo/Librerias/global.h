#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void esperar(){
	
    #ifdef __unix__

        printf("\nPulsa enter para continuar...");
        while(getchar()!='\n');

    #elif defined(_WIN32) || defined(WIN32)
		
		printf("\n");
        system("pause");

	#endif
        
}

void limpiar(){

    #ifdef __unix__

        system("clear");

    #elif defined(_WIN32) || defined(WIN32)

        system("cls");

    #endif     

}

// ***** SECCION DE AYUDA *****
void help(){

    printf("             COMANDO - FUNCION\n\n");

    printf("       **** SECCION DEL SISTEMA ****\n");
    printf("    --kernel-version - Muestra la version del kernel actual.\n");
    printf(" --running-processes - posero de procesos ejecutandose en el sistema.\n");
    printf("      --current-user - Muestra el nombre de usuario con el cual fue ejecutado el progama.\n");
    printf("         --date-time - Muestra la hora y fecha actual del sistema.\n");
    printf("            --uptime - Muestra el tiempo que ha estado encendida la computadora.\n\n");

    printf("       **** SECCION DE MEMORIA ****\n");
    printf("         --men-total - Total de memoria RAM.\n");
    printf("    --mem-total-free - Total de memorio RAM libre.\n");
    printf("          --men-swap - Total de memoria SWAP.\n");
    printf("     --mem-swap-free - Total de memoria SWAP libre en el sistema.\n\n");

    printf("       **** SECCION DEL DISCO ****\n");
    printf("         --disk-list - Lista de discos existentes en el sistema.\n");
    printf("        --disk-space - Muestra el espacio usado en los discos montados.\n");
    printf("   --partitions-list - Lista las particiones existentes en todos las unidades del sistema.\n\n");

    printf("      **** SECCION DE LA RED ****\n");
    printf("          --net-list - Lista las interfaces de red.\n");
    printf("       --net-list-ip - Lista las interfaces de red junto a su IP (si tiene asignada).\n\n");

}