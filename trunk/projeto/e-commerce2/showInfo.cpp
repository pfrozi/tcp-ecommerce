#include "showInfo.h"

//MOSTRA AS INFORMACOES DO PROGRAMA.
void showInfo()
{
     system("cls");
     mudaCor(Colors_YELLOW);
     printf("\nINFORMACOES DO PROGRAMA:");
     mudaCor(Colors_WHITE);
     printf("\n================================================================");
     printf("\nPrograma desenvolvido pelos alunos X e Y para a disciplina Z ");
     printf("\n O programa gera um arquivo chamado report.txt que contro");
     printf("\nla as vendas e suas respectivas datas e necessita dos arquivos");
     printf("\neletro.txt, vestuario.txt e usuarios.txt para controlar os esto-");
     printf("\nques e os cadastros.");
     printf("\n================================================================");
     fflush(stdin);
     getch();
}
//FIM DA FUNCAO QUE MOSTRA AS INFORMACOES DO PROGRAMA
