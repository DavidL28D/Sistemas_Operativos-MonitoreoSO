#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef __unix__ 

    #include <dirent.h>

    FILE *a;
    char linea[100];

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

        if ((a = fopen("/proc/version", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            while (!feof(a)){
                fgets(linea, sizeof(linea), a);
                
                if(strstr(linea, "Linux version")){
                    printf("%s", linea);
                }
            }

        }

        fclose(a);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void running_processes(){

    #ifdef __unix__

        DIR *dir;
        struct dirent *ent;
        int x = 0;
        bool flag;

        dir = opendir("/proc/");

        if (dir == NULL){
            printf("No se puede abrir el directorio.");

        }else{  

            while((ent = readdir (dir)) != NULL){
                // Nos devolverá el directorio actual 
                flag = true;

                for(int i=0; i<strlen(ent->d_name); i++){
                    if(!isdigit(ent->d_name[i])){
                        flag = false;
                        break;
                    }
                }

                if(flag){

                    //printf("%s\n", ent->d_name); //Imprime cada proceso encontrado
                    x++;

                }
            }

            printf("Actualmente existen %i procesos activos.", x);
            closedir (dir);

        }

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_total(){

    #ifdef __unix__

        if ((a = fopen("/proc/meminfo", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            while (!feof(a)){
                fgets(linea, sizeof(linea), a);
                
                if(strstr(linea, "MemTotal")){
                    printf("%s", linea);
                }
            }

        }

        fclose(a);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_total_free(){

    #ifdef __unix__

        

        if ((a = fopen("/proc/meminfo", "r")) == NULL){
            printf("No se puede abrir el archivo");
            
        }else{

            while (!feof(a)){
                fgets(linea, sizeof(linea), a);
                
                if(strstr(linea, "MemFree")){
                    printf("%s", linea);
                }
            }

        }

        fclose(a);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_swap(){

    #ifdef __unix__

        if ((a = fopen("/proc/meminfo", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            while (!feof(a)){
                fgets(linea, sizeof(linea), a);
                
                if(strstr(linea, "SwapTotal")){
                    printf("%s", linea);
                }
            }

        }

        fclose(a);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_swap_free(){

    #ifdef __unix__

        if ((a = fopen("/proc/meminfo", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            while (!feof(a)){
                fgets(linea, sizeof(linea), a);
                
                if(strstr(linea, "SwapFree")){
                    printf("%s", linea);
                }
            }

        }

        fclose(a);

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