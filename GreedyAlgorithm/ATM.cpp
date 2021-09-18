#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

//using namespace std;
#include <msclr\marshal_cppstd.h>


using namespace msclr::interop;
public class ATM {
	
	public :
		static ATM& getInstance()
		{
			static ATM  instance;
								 
			return instance;
		}
		typedef struct Cdm_Cashunit
		{
			int Type = 0;
			char UnitID[5] = "1234";
			short Denomination = 0; int Count = 0;
			int Maximum = 0;
			short Status = 0;
		} CASHUNIT, * LPCASHUNIT;

		typedef struct Cdm_Cu_Info
		{
			int Count = 5;
			LPCASHUNIT* lppList;
		} CUINFO, * LPCUINFO;

		
		int totalCash=0;
		CUINFO CUinfo = CUINFO();

	
	bool checkAtmHasCash() {
		if (totalCash <= 0)
		{
			return false;
		}
		return true;
	}
	bool checkAtmHasCash(int amount) {
		if (totalCash < amount)
		{
			return false;
		}
		return true;
	}
	bool updatecashunitstatus() {
	
	
		totalCash = gettotalcash();
		return true;
	}
	
	int gettotalcash() {
		
		int totalamount = 0;
		totalamount = (CUinfo.lppList[0]->Count * CUinfo.lppList[0]->Denomination) + (CUinfo.lppList[1]->Count * CUinfo.lppList[1]->Denomination) + (CUinfo.lppList[2]->Count * CUinfo.lppList[2]->Denomination);
		return totalamount;
	}

	bool parse_Cash_Information_units() {
		CUINFO testCUinfo = CUINFO();
		
		testCUinfo.Count = 5;
		LPCASHUNIT* testcashunit = new LPCASHUNIT[testCUinfo.Count];
		for (int i = 0; i < testCUinfo.Count; i++) {
			testcashunit[i] = new CASHUNIT();
		}
		
		testCUinfo.lppList = testcashunit;
			
		
		
		testcashunit[0]->Count = 500;
			testcashunit[0]->Type = 0;
			strcpy_s(testcashunit[0]->UnitID,  "1stb");
			testcashunit[0]->Denomination = 500;
			testcashunit[0]->Maximum = 100;
			testcashunit[0]->Status = 0;

			testcashunit[1]->Count = 500;
			testcashunit[1]->Type = 0;
			strcpy_s(testcashunit[1]->UnitID, "2ndb");
			testcashunit[1]->Denomination = 1000;
			testcashunit[1]->Maximum = 100;
			testcashunit[1]->Status = 0;

			testcashunit[2]->Count = 500;
			testcashunit[2]->Type = 0;
			strcpy_s(testcashunit[2]->UnitID, "3rdb");
			testcashunit[2]->Denomination = 2000;
			testcashunit[2]->Maximum = 100;
			testcashunit[2]->Status = 0;
			
			
			testcashunit[3]->Count = 500;
			testcashunit[3]->Type = 1; //reject
			strcpy_s(testcashunit[3]->UnitID, "rjct");
			testcashunit[3]->Denomination = 0;
			testcashunit[3]->Maximum = 0;
			testcashunit[3]->Status = 0;
			
			
			testcashunit[4]->Count = 500;
			testcashunit[4]->Type = 2; // retract
			strcpy_s(testcashunit[4]->UnitID, "rtct");
			testcashunit[4]->Denomination = 0;
			testcashunit[4]->Maximum = 100;
			testcashunit[4]->Status = 0;
			
			this->CUinfo = testCUinfo;

			return true;
	}

	

	bool startTransaction(System::String^ amount) {
		msclr::interop::marshal_context context;
		std::string std_stringamount = context.marshal_as<std::string>(amount);
		int iAmount = std::stoi(std_stringamount);
		printf("Start Transaction Amount Entered: %d", iAmount);

		return checkAtmHasCash(iAmount);
		
	}

	

	
};








