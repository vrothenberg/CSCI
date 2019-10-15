#include "Countries.h"
#include "CinReader.h"

// Primary loop, can take optional file argument for populating _countriesv
int main(int argc, char* argv[]) {
  string file;
  CinReader read;

  // Check arguments for
  if(argc == 1) {
    // No file provided
    // Default file "countries.csv"
    file = "countries.csv";
  } else if (argc == 2) {
    // File name provided
    file = argv[1];
  } else {
    file = argv[1];
    cout << "Invalid number of arguments\n";
  }

  bool inUse = true;
  string readCharString = "eEnNpPaAdDmMgGlLbB";
  while(inUse) {
    ClearScreen();
    cout << "Country Data Viewer\n\n";
    // Create Countries object to hold vector of Country objects
    Countries MyCountries(file);
    cout << "\nSystem Options\n"
         << "(N) New CSV file\n"
         << "(E) Exit\n\n"
         << "Data viewing options\n"
         << "(P) Population\n"
         << "(A) Area\n"
         << "(D) Population Density\n"
         << "(M) Net Migration\n"
         << "(G) GDP Per Capita\n"
         << "(L) Literacy\n"
         << "(B) Birthrate\n"
         << "Select your option: ";

    char choice = toupper(read.readChar(readCharString));
    int num = 10;
    bool hilo = false;
    char b;

    switch(choice) {
      case 'E':
        // Exit selected
        ClearScreen();
        inUse = false;
        break;
      case 'N':
        // New file
        ClearScreen();
        cout << "New Country Data\n"
             << "Specify .csv filename\n";
        file = read.readString();
        if(MyCountries.ReadFile(file)) {
          cout << "New file data successfully added.\n";
        } else {
          cout << "ERROR!  New file data failed to add.\n"
               << "Check if filename is accurate and located in Data Viewer local folder.\n";
        };
        ContinuePrompt();
        break;

      // Data viewing options
      case 'P':
        // Population
        ClearScreen();
        cout << "Country Data Viewer: Population\n"
             << "Specify number of countries to view: ";
        num = read.readInt(0, MyCountries.GetSize());
        cout << "Specify (H)ighest or (L)owest: ";
        b = toupper(read.readChar("hHlL"));
        if(b == 'L') hilo = true;
        ClearScreen();
        MyCountries.Populous(hilo, num);
        break;
      case 'A':
        // Area
        ClearScreen();
        cout << "Country Data Viewer: Area\n"
             << "Specify number of countries to view: ";
        num = read.readInt(0, MyCountries.GetSize());
        cout << "\nSpecify (H)ighest or (L)owest: ";
        b = toupper(read.readChar("hHlL"));
        if(b == 'L') hilo = true;
        ClearScreen();
        MyCountries.Area(hilo, num);
        break;
      case 'D':
        // Population Density
        ClearScreen();
        cout << "Country Data Viewer: Population Density\n"
             << "Specify number of countries to view: ";
        num = read.readInt(0, MyCountries.GetSize());
        cout << "Specify (H)ighest or (L)owest: ";
        b = toupper(read.readChar("hHlL"));
        if(b == 'L') hilo = true;
        ClearScreen();
        MyCountries.PopDensity(hilo, num);
        break;
      case 'M':
        // Net Migration
        ClearScreen();
        cout << "Country Data Viewer: Net Migration\n"
             << "Specify number of countries to view: ";
        num = read.readInt(0, MyCountries.GetSize());
        cout << "Specify (H)ighest or (L)owest: ";
        b = toupper(read.readChar("hHlL"));
        if(b == 'L') hilo = true;
        ClearScreen();
        MyCountries.NetMigration(hilo, num);
        break;
      case 'G':
        // GDP Per Capita
        ClearScreen();
        cout << "Country Data Viewer: GDP Per Capita\n"
             << "Specify number of countries to view: ";
        num = read.readInt(0, MyCountries.GetSize());
        cout << "Specify (H)ighest or (L)owest: ";
        b = toupper(read.readChar("hHlL"));
        if(b == 'L') hilo = true;
        ClearScreen();
        MyCountries.GDPCapita(hilo, num);
        break;
      case 'L':
        // Literacy
        ClearScreen();
        cout << "Country Data Viewer: Literacy\n"
             << "Specify number of countries to view: ";
        num = read.readInt(0, MyCountries.GetSize());
        cout << "Specify (H)ighest or (L)owest: ";
        b = toupper(read.readChar("hHlL"));
        if(b == 'L') hilo = true;
        ClearScreen();
        MyCountries.Literacy(hilo, num);
        break;
      case 'B':
        // Birthrate
        ClearScreen();
        cout << "Country Data Viewer: Birthrate\n"
             << "Specify number of countries to view: ";
        num = read.readInt(0, MyCountries.GetSize());
        cout << "Specify (H)ighest or (L)owest: ";
        b = toupper(read.readChar("hHlL"));
        if(b == 'L') hilo = true;
        ClearScreen();
        MyCountries.Birthrate(hilo, num);
        break;
      default:
        cout << "ERROR! Shouldn't be here.\n";
        break;
    }
  }
  return 0;
}
