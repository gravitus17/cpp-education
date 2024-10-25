#include <iostream>
#include <vector>
#include <limits>

using namespace std;

enum type_room
{
    livingroom,
    children,
    bathroom,
    bedroom,
    kitchen
};

enum building_type
{
    residential,
    garage,
    barn,
    bathhouse
};
struct Room
{
    string name;
    type_room type;
    double area =0;
};

struct Floor
{
    int floor_number;
    vector <Room> rooms;
    double height = 0;  

    void addRoom(Room &room)
    {
        rooms.push_back(room);
    }
    //count all room area
    double countArea(vector<Room> rooms)
    {
        double room_area =0;
        for (Room room : rooms)
           room_area += room.area;
        
        return room_area;
    }
    
};

struct Building
{
    string name;
    building_type type;
    double building_area = 0;
    bool has_chimney = false;
    vector <Floor> floors;
    void addFloor(Floor floor)
    {
        floors.push_back(floor);
    }
};

struct Sector
{
    int sector_id;
    vector <Building> buildings;

    void addBuilding(Building& building)
    {
        buildings.push_back(building);
    }

};

struct Village
{
    vector <Sector> sectors; 

    void addSector(Sector& sector)
    {
        sectors.push_back(sector);
    }
   
};

int controlInput(int max_size = numeric_limits<int>::max(), int min_size = 0 )
{
    while(true)
    {
        int value; 
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n'|| value < min_size || value > max_size)  
        {
            std::cerr << "Error input\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
        }
    }
}
double controlDouble(int size = numeric_limits<int>::max())
{
    while(true)
    {
        double value; 
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n'|| value < 0 || value > size)  
        {
            std::cerr << "Error input\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
        }
    }
}


void createRoom(Floor &floor, Building &building ,int room_num)
{
    for( int i = 0; i < room_num; i++)
    {
        Room room;
        floor.addRoom(room);
        Room  existed_room;
        double existed_area;

        cout << "Enter number's type of room:\n1.Living room\n2.Children's room\n" <<
            "3.Bathroom\n4.Bedroom\n5.Kitchen\n";
        int room_type = controlInput(5,1) -1;

        cout << "Enter the area of room: ";
        if (i == 0)
            room.area =  controlDouble(int((building.building_area)));
        else
            //Remove already input room area from building area
            existed_room = floor.rooms[i-1];
            existed_area = building.building_area - existed_room.area;
            room.area =  controlDouble(int(existed_area));

        //check room type ant create;
        switch (room_type)
        {
        case 0:
            {
                room.type = livingroom;
                room.name = "Living room";
                break;
            }
        case 1:
            {   
                room.type = children;
                room.name = "Children's room";
                break;
            }
        case 2:
            {
                room.type = bathroom;
                room.name = "Bathroom";
                break;
            }
        case 3:
            {
                room.type = bedroom;
                room.name = "Bedroom";
                break;
            }
        case 4:
            {
            room.type = kitchen;
            room.name = "Kitchen";
            break;
            }
        }

    }
}

// Get chimney value from user
void hasChimney(Building &building)
{
    string user_input;
    while(true)
    {
        cout << "Does House or Bathhouse have chimney: yes/no ?\n";
        cin >> user_input;

        if( user_input == "yes")
        {
            building.has_chimney = true;
            return;
        }
        else if( user_input == "no")
            return;
        else
        {
            cout << "Wrong Input!\n";
        }
    }
}

//create variable of Floor
void createFloor(Building &building,  int & floors)
{
    for(int i = 1; i <= floors; i++)
    {   
        Floor floor;
        floor.floor_number = i;

        cout << "Enter ceiling heing on the floor " << i <<endl;
        floor.height = controlDouble(8);

        cout << "Enter number of room on floor " << i <<"(min: 2, max:4)\n";
        int room_number = controlInput(4,2);
        createRoom(floor, building, room_number);
        building.addFloor(floor);
    }
}

// Create a variable of Building
void createBuilding(Sector &sector, int &i)
{
    int buildings;

    
    cout << "Input number of buildings on  sector №" << i << endl;
    buildings = controlInput(4);

    
    for( int i = 0; i < buildings; i++)
    {
        Building building;
        sector.addBuilding(building);

        int building_type;
        cout << "Input type number of building:\n1.Residential home\n2.Garage\n3.Barn\n4.Bathhouse\n";
        building_type = controlInput(4)-1;

        cout << "Enter the area of building: ";
        building.building_area =  controlDouble(1000);

        // Check what type building
        switch (building_type)
        {
            case 0:
            {
                building.name = "Residential House";
                building.type = residential;
                hasChimney(building);

                cout << " Enter number of floor in house(between 1-3)\n";
                int floors = controlInput(3,1);
                createFloor(building, floors);
                break;
            }
            case 1:
            {
                building.name = "Garage";
                building.type = garage;
                break;
            }
            case 2:
            {
                building.name = "Barn";
                building.type = barn;
                break;
            }
            case 3:
            {
                building.name = "Bathhouse";
                building.type = bathhouse;
                hasChimney(building);
                break;
            }
        }
    }
}

void createVillage()
{
    int amount;
    cout << "Input number of sector in the village: ";
    amount = controlInput(1000);
    Village town;
    for (int i = 1; i <= amount; i++)
    {   
        //create a sector
        Sector sector;
        sector.sector_id = i;

        town.addSector(sector);
        createBuilding(sector, i);
    }
}
int main()
{
    createVillage();
}