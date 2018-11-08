#include "../libreria.h"

int main(int argc, char **argv){

    if(argc < 3){

        if(strcmp(argv[1], "--kernel-version") == 0){
            kernel_version();            

        }else if(strcmp(argv[1], "--running-processes") == 0){
            running_processes();

        }else if(strcmp(argv[1], "--mem-total") == 0){
            mem_total();
            
        }else if(strcmp(argv[1], "--mem-total-free") == 0){
            mem_total_free();
            
        }else if(strcmp(argv[1], "--mem-swap") == 0){
            mem_swap();
            
        }else if(strcmp(argv[1], "--mem-swap-free") == 0){
            mem_swap_free();
            
        }else if(strcmp(argv[1], "--disk-list") == 0){
            disk_list();
            
        }else if(strcmp(argv[1], "--partitions-list") == 0){
            partitions_list();
            
        }else if(strcmp(argv[1], "--net-list") == 0){
            net_list();
            
        }else if(strcmp(argv[1], "--net-list-ip") == 0){
            net_list_ip();
            
        }else if(strcmp(argv[1], "--disk-space") == 0){
            disk_space();
            
        }else if(strcmp(argv[1], "--current-user") == 0){
            current_user();
            
        }else if(strcmp(argv[1], "--date-time") == 0){
            date_time();
            
        }else if(strcmp(argv[1], "--uptime") == 0){
            uptime();
            
        }else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){
            help();
            
        }else{
            printf("Argumento ingresado incorrecto, pulse -h o --help para recibir ayuda.");
        }
        

    }else{
        printf("Cantidad de argumentos invalido.");
    }

    return 0;
}