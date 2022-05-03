#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFor1Lab
{
	TEST_CLASS(UnitTestFor1Lab)
	{
	public:
		
		TEST_METHOD(constuctorTest)
		{
			MyMap<int, int> TestMap;
			TestMap.insert(33, 10);
			Assert::IsTrue(TestMap.findForValue(33) == 10);
			
		}

		TEST_METHOD(insertTest) 
		{
			MyMap<int, int> TestMap;

			TestMap.insert(33, 10);
			TestMap.insert(13, 20);

			Assert::IsTrue(TestMap.find(33)->value == 10);
			Assert::IsTrue(TestMap.find(13)->value == 20);
			
			
		}

		TEST_METHOD(get_keysTest)
		{
			MyMap<int, int> TestMap;

			List<int> TestList;

			TestMap.insert(33, 10);
			TestMap.insert(13, 20);
			TestMap.insert(53, 30);
			TestMap.insert(11, 40);
			TestMap.insert(21, 50);
			TestMap.insert(41, 60);

			TestList = TestMap.get_keys();

			Assert::AreEqual(TestList.at(0), 33);
			Assert::AreEqual(TestList.at(1), 13);
			Assert::AreEqual(TestList.at(2), 53);
			Assert::AreEqual(TestList.at(3), 11);
			Assert::AreEqual(TestList.at(4), 21);
			Assert::AreEqual(TestList.at(5), 41);
		}

		TEST_METHOD(get_valuesTest)
		{
			MyMap<int, int> TestMap;

			List<int> TestList;

			TestMap.insert(33, 10);
			TestMap.insert(13, 20);
			TestMap.insert(53, 30);
			TestMap.insert(11, 40);
			TestMap.insert(21, 50);
			TestMap.insert(41, 60);

			TestList = TestMap.get_values();

			Assert::AreEqual(TestList.at(0), 10);
			Assert::AreEqual(TestList.at(1), 20);
			Assert::AreEqual(TestList.at(2), 30);
			Assert::AreEqual(TestList.at(3), 30);
			Assert::AreEqual(TestList.at(4), 50);
			Assert::AreEqual(TestList.at(5), 60);
		}

		TEST_METHOD(findTest)
		{

			MyMap<int, int> TestMap;

			TestMap.insert(33, 10);
			TestMap.insert(13, 20);

			Assert::IsTrue(TestMap.find(33)->value == 10);
			Assert::IsTrue(TestMap.find(13)->value == 20);
			
			try
			{
				TestMap.find(1);
			}
			catch (const invalid_argument e)
			{
				Assert::AreEqual("This element is not in the tree", e.what());
			}
		}

		TEST_METHOD(findForValueTest) 
		{

			MyMap<int, int> TestMap;

			TestMap.insert(33, 10);
			TestMap.insert(13, 20);

			Assert::IsTrue(TestMap.findForValue(33) == 10);
			Assert::IsTrue(TestMap.findForValue(13) == 20);

			try
			{
				TestMap.find(1);
			}
			catch (const invalid_argument e)
			{
				Assert::AreEqual("This element is not in the tree", e.what());
			}

		}

		TEST_METHOD(removeTest)
		{

			MyMap<int, int> TestMap;

			TestMap.insert(33, 10);
			TestMap.insert(13, 20);

			TestMap.remove(13);

			Assert::IsTrue(TestMap.findForValue(33) == 10);
			
			try
			{
				TestMap.find(13);
			}
			catch (const invalid_argument e)
			{
				Assert::AreEqual("This element is not in the tree", e.what());
			}
		}
	};
}
