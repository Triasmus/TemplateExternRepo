#include "ProtoFiles/candy.pb.h"
#include <fstream>
#include <iostream>
#include <string>
#include <google/protobuf/text_format.h>
#include <google/protobuf/util/json_util.h>

int promptForAmount()
{
  int amount;
  std::cout << "Enter how many: ";
  std::cin >> amount;
  std::cin.ignore(256, '\n');
  return amount;
}

void promptForCandy(tutorial::Candy *candy)
{
  std::cout << "Enter Candy Name: ";
  std::getline(std::cin, *candy->mutable_name());

  int id;
  std::cout << "Enter id: ";
  std::cin >> id;
  candy->set_id(id);
  std::cin.ignore(256, '\n');

  std::cout << "Enter type of chocolate: ";
  std::string type;
  getline(std::cin, type);
  if (!type.empty())
  {
    if (type == "milk")
    {
      candy->set_type(tutorial::Candy_ChocolateType_MILK_CHOCOLATE);
    }
    else if (type == "dark")
    {
      candy->set_type(tutorial::Candy_ChocolateType_DARK_CHOCOLATE);
    }
    else if (type == "white")
    {
      candy->set_type(tutorial::Candy_ChocolateType_WHITE_CHOCOLATE);
    }
  }

  int width;
  std::cout << "Enter width: ";
  std::cin >> width;
  candy->mutable_size()->set_width(width);
  std::cin.ignore(256, '\n');
  int height;
  std::cout << "Enter height: ";
  std::cin >> height;
  candy->mutable_size()->set_height(height);
  std::cin.ignore(256, '\n');
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " CANDY_ORDER_FILE" << std::endl;
    return -1;
  }

  tutorial::Order order;
  {
    std::fstream input(argv[1], std::ios::in | std::ios::binary);
    if (!input)
    {
      std::cout << argv[1] << ": File not found. Creating a new file."
                << std::endl;
    }
    else if (!order.ParseFromIstream(&input))
    {
      std::cout << "Failed to parse address book." << std::endl;
      return -1;
    }
  }
  std::string nextCommand;
  do
  {
    std::cout << "What would you like to do: \n"
                 "1) Add a candy\n"
                 "2) See a candy\n"
                 "3) See all Candy\n"
                 "0) exit\n";
    std::getline(std::cin, nextCommand);
    if (nextCommand == "1")
    {
  promptForCandy(order.add_candy());
  order.add_amount(promptForAmount());

    }
    if (nextCommand == "2")
    {
      std::cout << "What candy would you like to See?" << std::endl;
      std::string toSee;
      std::getline(std::cin, toSee);
      for (size_t i = 0; i < order.candy_size(); i++) {
        if (order.candy(i).name() == toSee)
        {
          std::string toPrint;
          //google::protobuf::util::MessageToJsonString(order.candy(i), &toPrint, google::protobuf::util::JsonPrintOptions());
          google::protobuf::TextFormat::PrintToString(order.candy(i), &toPrint);
          std::cout << toPrint << std::endl;
        }
      }
    }
    if (nextCommand == "3")
    {
      for (size_t i = 0; i < order.candy_size(); i++) {
          std::string toPrint;
          google::protobuf::TextFormat::PrintToString(order.candy(i), &toPrint);
          std::cout << toPrint << std::endl;
          std::cout << "Amount: " << order.amount(i) << std::endl;
      }
    }
  } while (nextCommand != "0");


  std::fstream output(argv[1],
                      std::ios::out | std::ios::trunc | std::ios::binary);
  if (!order.SerializeToOstream(&output))
  {
    std::cerr << "Failed to write address book. " << std::endl;
    return -1;
  }
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
