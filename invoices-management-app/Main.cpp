#include <cstdlib>
#include <crtdbg.h>
#include "Menu.h"
#include "Unit.h"
#include <iomanip>

int main(int argc, char* argv[])
{
        std::string fileNameVAT,
            fileNameUnit,
            fileNameInvoices;

        if (argc < 7) {
            std::cout << "Niewystarczajaca ilosc argumentow!" << std::endl << "Dla pliku z wartosciami VAT uzyj przelacznika -v, dla pliku z jednostakmi sprzedazy uzyj przelacznika -u, dla pliku z fakturami uzyj przelacznika -i." << std::endl;
            return 0;
        }

        for (int i = 0; i < argc; i++)
        {
            char* param = argv[i];
            if (!strcmp(param, "-v"))
            {
                std::string name = argv[i + 1];

                if (name != "VATrates.txt")
                {
                    std::cout << "Plik nie zostal znaleziony!" << std::endl;
                    return 0;
                }

                fileNameVAT = name;
            }

            if (!strcmp(param, "-u"))
            {
                std::string name = argv[i + 1];
                if (name != "Units.txt")
                {
                    std::cout << "Plik nie zostal znaleziony!" << std::endl;
                    return 0;
                }

                fileNameUnit = name;
            }

            if (!strcmp(param, "-i"))
            {
                std::string name = argv[i + 1];
                if (name != "Invoices.txt")
                {
                    std::cout << "Plik nie zostal znaleziony!" << std::endl;
                    return 0;
                }

                fileNameInvoices = name;
            }
        }

        FileManagement filemanagement(fileNameVAT, fileNameUnit, fileNameInvoices);
        Menu mainMenu(filemanagement);

        mainMenu.RunProgram();

        return 0;
}