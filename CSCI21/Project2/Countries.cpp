#include "Countries.h"
#include "CinReader.h"


// Clears screen, works with Windows as well as OSX and *nix
void ClearScreen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
};

// Pauses screen so information can be displayed
void ContinuePrompt() {
  CinReader read;
  string cont;
  cout << "\nEnter any key to continue...\n";
  cont = read.readString();
};

// Constructor, takes csv file of countries as input
Countries::Countries(string file) {
  if(this->ReadFile(file)) {
    cout << "Successfully opened " << file << endl;
  } else {
    cout << "ERROR!  Failed to open " << file << endl;
  }
};

// Reads data from filename into Country objects
// Adds Country objects into private _countriesv vector
bool Countries::ReadFile(string file) {
  ifstream fin(file);
  string line, token;
  int pos;
  if (fin.is_open()) {
    this->_countriesv.clear();
    string delim = ",";
    vector<string> categories;

    // First line of csv file are headers, stored in categories vector
    getline(fin,line);
    pos = line.find(delim);
    token = line.substr(0,pos);
    categories.push_back(token);
    for (int i = 1; i < 8; i++) {
      line = line.substr(pos+delim.size());
      pos = line.find(delim);
      token = line.substr(0,pos);
      categories.push_back(token);
    }

    // Primary file input loop
    while(getline(fin,line)) {
      try {
        vector<string> attr;
        pos = line.find(delim);
        string name = line.substr(0,pos);
        attr.push_back(name);
        for (int i = 1; i < 8; i++) {
          line = line.substr(pos+delim.size());
          pos = line.find(delim);
          token = line.substr(0,pos);
          attr.push_back(token);
        }
        // Line of country data fully parsed and tokenized, ready to be added to _countriesv
        AddCountry(attr);
      } catch (const std::exception &e) {
        // Shouldn't occur normally
        // AddCountry function handles empty fields and sets to 0
        cout << "ERROR!\n";
      }

    }
    return true;
  }
  return false;
};

// Creates country object from vector of tokens and adds to _countriesv
void Countries::AddCountry(vector<string> attr) {
  // Check if any fields are empty, default to "0"
  for (int i = 0; i < attr.size(); i++) {
    if (attr[i] == "") attr[i] = "0";
  }
  // Initialize Country struct, convert to necessary data type
  Country nc = {attr[0], stoul(attr[1]), stoul(attr[2]), stod(attr[3]),
    stod(attr[4]), stoul(attr[5]), stod(attr[6]), stod(attr[7])};

  this->_countriesv.push_back(nc);
};

// Returns size of _countriesv
// Prevents out of bounds error when user specifies too many elements for display
int Countries::GetSize() {
  return this->_countriesv.size();
}

// Data viewing functions
// Displays sorted list of num length based on column attribute
// Displays top or bottom based on bool lohi, false = top

// Population
void Countries::Populous(bool lohi, int num) {

  // Sort call, uses algorithm library to sort entire _countriesv vector
  // Third argument is lambda function which compares based on _population
  // The boolean variable lohi must be passed to lambda for scope resolution
  // Displays by ascending or descending based on the boolean variable lohi
  sort(this->_countriesv.begin(), this->_countriesv.end(),
  [lohi]( const Country &left, const Country &right )
                 { return lohi ? left._population < right._population
                   : left._population > right._population; });


  printf("%s %d Countries based on Population \n\n", lohi ? "Bottom" : "Top", num);
  printf("%-15s %-15s \n\n", "Name", "Population");

  // Displays integer variable num of elements
  for(int i = 0; i < num; i++) {
    Country &c = this->_countriesv.at(i);
    printf("%-15s %-10u \n", c._name.substr(0,15).c_str(), c._population);
  }

  // Pauses to display information
  ContinuePrompt();
};

// Area
void Countries::Area(bool lohi, int num) {

  // Sort call, uses algorithm library to sort entire _countriesv vector
  // Third argument is lambda function which compares based on Country struct data member _area
  // The boolean variable lohi must be passed to lambda for scope resolution
  // Displays by ascending or descending based on the boolean variable lohi
  sort(this->_countriesv.begin(), this->_countriesv.end(),
  [lohi]( const Country &left, const Country &right )
                 { return lohi ? left._area < right._area
                   : left._area > right._area; });

  printf("%s %d Countries based on Area \n\n", lohi ? "Bottom" : "Top", num);
  printf("%-15s %-10s \n\n", "Name", "Area (sq. mi.)");

  // Displays integer variable num of elements
  for(int i = 0; i < num; i++) {
    Country &c = this->_countriesv.at(i);
    printf("%-15s %-10u \n", c._name.substr(0,15).c_str(), c._area);
  }

  // Pauses to display information
  ContinuePrompt();
};

// Population Density
void Countries::PopDensity(bool lohi, int num) {

  // Sort call, uses algorithm library to sort entire _countriesv vector
  // Third argument is lambda function which compares based on Country struct data member _popdensity
  // The boolean variable lohi must be passed to lambda for scope resolution
  // Displays by ascending or descending based on the boolean variable lohi
  sort(this->_countriesv.begin(), this->_countriesv.end(),
  [lohi]( const Country &left, const Country &right )
                 { return lohi ? left._popdensity < right._popdensity
                   : left._popdensity > right._popdensity; });

  printf("%s %d Countries based on Population Density \n\n", lohi ? "Bottom" : "Top", num);
  printf("%-15s %-20s \n\n", "Name", "Population Density (per sq. mi.)");
  // Displays integer variable num of elements
  for(int i = 0; i < num; i++) {
    Country &c = this->_countriesv.at(i);
    printf("%-15s %-10.1f \n", c._name.substr(0,15).c_str(), c._popdensity);
  }

  // Pauses to display information
  ContinuePrompt();
};

// Net Migration
void Countries::NetMigration(bool lohi, int num) {

  // Sort call, uses algorithm library to sort entire _countriesv vector
  // Third argument is lambda function which compares based on Country struct data member _netmigration
  // The boolean variable lohi must be passed to lambda for scope resolution
  // Displays by ascending or descending based on the boolean variable lohi
  sort(this->_countriesv.begin(), this->_countriesv.end(),
  [lohi]( const Country &left, const Country &right )
                 { return lohi ? left._netmigration < right._netmigration
                   : left._netmigration > right._netmigration; });

  printf("%s %d Countries based on Net Migration \n\n", lohi ? "Bottom" : "Top", num);
  printf("%-15s %-20s \n\n", "Name", "Net Migration");
  // Displays integer variable num of elements
  for(int i = 0; i < num; i++) {
    Country &c = this->_countriesv.at(i);
    printf("%-15s %-10.2f \n", c._name.substr(0,15).c_str(), c._netmigration);
  }

  // Pauses to display information
  ContinuePrompt();
};

// GDP Per Capita
void Countries::GDPCapita(bool lohi, int num) {

  // Sort call, uses algorithm library to sort entire _countriesv vector
  // Third argument is lambda function which compares based on Country struct data member _gdpcapita
  // The boolean variable lohi must be passed to lambda for scope resolution
  // Displays by ascending or descending based on the boolean variable lohi
  sort(this->_countriesv.begin(), this->_countriesv.end(),
  [lohi]( const Country &left, const Country &right )
                 { return lohi ? left._gdpcapita < right._gdpcapita
                   : left._gdpcapita > right._gdpcapita; });

  printf("%s %d Countries based on GDP Per Capita \n\n", lohi ? "Bottom" : "Top", num);
  printf("%-15s %-20s \n\n", "Name", "GDP ($ Per Capita)");
  // Displays integer variable num of elements
  for(int i = 0; i < num; i++) {
    Country &c = this->_countriesv.at(i);
    printf("%-15s %-10u \n", c._name.substr(0,15).c_str(), c._gdpcapita);
  }

  // Pauses to display information
  ContinuePrompt();
};

// Literacy
void Countries::Literacy(bool lohi, int num) {

  // Sort call, uses algorithm library to sort entire _countriesv vector
  // Third argument is lambda function which compares based on Country struct data member _literacy
  // The boolean variable lohi must be passed to lambda for scope resolution
  // Displays by ascending or descending based on the boolean variable lohi
  sort(this->_countriesv.begin(), this->_countriesv.end(),
  [lohi]( const Country &left, const Country &right )
                 { return lohi ? left._literacy < right._literacy
                   : left._literacy > right._literacy; });

  printf("%s %d Countries based on Literacy \n\n", lohi ? "Bottom" : "Top", num);
  printf("%-15s %-20s \n\n", "Name", "Literacy (%)");
  // Displays integer variable num of elements
  for(int i = 0; i < num; i++) {
    Country &c = this->_countriesv.at(i);
    printf("%-15s %-10.1f \n", c._name.substr(0,15).c_str(), c._literacy);
  }

  // Pauses to display information
  ContinuePrompt();
};

// Birthrate
void Countries::Birthrate(bool lohi, int num) {

  // Sort call, uses algorithm library to sort entire _countriesv vector
  // Third argument is lambda function which compares based on Country struct data member _birthrate
  // The boolean variable lohi must be passed to lambda for scope resolution
  // Displays by ascending or descending based on the boolean variable lohi
  sort(this->_countriesv.begin(), this->_countriesv.end(),
  [lohi]( const Country &left, const Country &right )
                 { return lohi ? left._birthrate < right._birthrate
                   : left._birthrate > right._birthrate; });

  printf("%s %d Countries based on Birthrate \n\n", lohi ? "Bottom" : "Top", num);
  printf("%-15s %-20s \n\n", "Name", "Birthrate");
  // Displays integer variable num of elements
  for(int i = 0; i < num; i++) {
    Country &c = this->_countriesv.at(i);
    printf("%-15s %-10.2f \n", c._name.substr(0,15).c_str(), c._birthrate);
  }

  // Pauses to display information
  ContinuePrompt();
};
