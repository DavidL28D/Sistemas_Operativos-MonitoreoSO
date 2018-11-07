#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__

    // includes para linux

#elif defined(_WIN32) || defined(WIN32)

    // includes para windows
#endif

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

void kernel_version(){

    #ifdef __unix__



    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void running_processes(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_total(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_total_free(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_swap(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_swap_free(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void disk_list(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void partitions_list(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void net_list(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void net_list_ip(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void disk_space(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void current_user(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void date_time(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void uptime(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void help(){

   printf("             COMANDO - FUNCION\n");
   printf("    --kernel-version - Muestra la version del kernel actual.\n");
   printf(" --running-processes - Numero de procesos ejecutandose en el sistema.\n");
   printf("         --men-total - Total de memoria RAM.\n");
   printf("    --mem-total-free - Total de memorio RAM libre.\n");
   printf("          --men-swap - Total de memoria SWAP.\n");
   printf("     --mem-swap-free - Total de memoria SWAP libre en el sistema.\n");
   printf("         --disk-list - Lista de discos existentes en el sistema.\n");
   printf("   --partitions-list - Lista las particiones existentes en todos las unidades del sistema.\n");
   printf("          --net-list - Lista las interfaces de red.\n");
   printf("       --net-list-ip - Lista las interfaces de red junto a su IP (si tiene asignada).\n");
   printf("        --disk-space - Muestra el espacio usado en los discos montados.\n");
   printf("      --current-user - Muestra el nombre de usuario con el cual fue ejecutado el progama.\n");
   printf("         --date-time - Muestra la hora y fecha actual del sistema.\n");
   printf("            --uptime - Muestra el tiempo que ha estado encendida la computadora.\n");

}