#include <QtTest>
#include "ProtoFiles/candy.pb.h"

class ProtoFilesTest : public QObject
{
  Q_OBJECT

public:
  ProtoFilesTest();
  ~ProtoFilesTest();

  private slots:
  void initTestCase();
  void cleanupTestCase();
  void candy();
};

ProtoFilesTest::ProtoFilesTest()
{
}

ProtoFilesTest::~ProtoFilesTest()
{
}

void ProtoFilesTest::initTestCase()
{
}

void ProtoFilesTest::cleanupTestCase()
{
  google::protobuf::ShutdownProtobufLibrary();
}

void ProtoFilesTest::candy()
{
  tutorial::Candy* candy = new tutorial::Candy();
  candy->set_name("m&ms");
  tutorial::Candy::Size* size = new tutorial::Candy::Size();
  size->set_height(2);
  size->set_width(2);
  candy->set_allocated_size(size);
  candy->set_id(1245);
  candy->set_type(tutorial::Candy::ChocolateType::Candy_ChocolateType_MILK_CHOCOLATE);

  auto sString = candy->SerializeAsString();
  tutorial::Candy returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.name() == "m&ms");
  QVERIFY(returnedMsg.size().height() == 2);
  QVERIFY(returnedMsg.size().width() == 2);
  QVERIFY(returnedMsg.id() == 1245);
  QVERIFY(returnedMsg.notused() == 0);
  QVERIFY(returnedMsg.type() == tutorial::Candy::ChocolateType::Candy_ChocolateType_MILK_CHOCOLATE);
}

QTEST_APPLESS_MAIN(ProtoFilesTest)

#include "ProtoFilesTestMain.moc"
