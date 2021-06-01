// Eigen After Basic Math.cpp : Defines the entry point for the application.
//

#include "Eigen After Basic Math.h"


int main()
{
	std::cout << "Hello Eigen" << std::endl;
	Eigen::Matrix2d mat;
	mat << 1, 2, 3, 4;
	std::cout << "Testing Eigen\n" <<mat<< std::endl;
	std::cout << "Array class provides general purpose arrays " << std::endl;
	//working with array 
	Eigen::Array<float, 3, 1> arrayOneDimension;
	Eigen::Array<double, 3, 3> TwoDimen;

	std::cout << "Accessing values inside an array" << std::endl;
	Eigen::ArrayXXf m(2, 2);
	m << 1, 2, 3, 4;
	m(0, 0) = 9;
	std::cout << "Try accesing an array \n" <<m<< std::endl;

	std::cout << "Addition and subtraction" << std::endl;
	Eigen::ArrayXXf a(3, 3), b(3, 3);
	a << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;
	b << 1, 2, 3,
		1, 2, 3,
		1, 2, 3;
	std::cout << "adding two array is done coefficient wise (a+b) = \n" << a+b<< std::endl;
	std::cout << "Subtracting a scalar from an array (a-2)\n" << a - 2 << std::endl;

	std::cout << "Interpret multiplication  as coefficient-wise  product " << std::endl;
	Eigen::ArrayXXd aDouble(3, 3),bDoubl(3,3);
	aDouble << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;
	bDoubl << 1, 2, 3,
		1, 2, 3,
		1, 2, 3;

	std::cout << "Multiply two array\n" <<aDouble*bDoubl<< std::endl;
	std::cout << "Other coefficent wise operations" << std::endl;
	Eigen::ArrayXd aTest =Eigen::ArrayXd::Random(5);
	std::cout << "Array element : \n" << aTest << std::endl;
	std::cout << "Absoulte value from the current array \n" << aTest.abs()<< std::endl;
	std::cout << "Absoulte value and square root from the current array \n" << aTest.abs().sqrt() << std::endl;
	aTest *= 2;
	std::cout << "Multiplying the current scalar\n"<< aTest << std::endl;

	std::cout << "Converting between an array and Matrix ecpression" << std::endl;
	Eigen::MatrixXf mConvert(2, 2);
	Eigen::MatrixXf nConvert(2, 2);
	Eigen::MatrixXf nResult(2, 2);
	mConvert << 1, 2, 3, 4;
	nConvert << 5, 6, 7, 8;
	nResult = mConvert * nConvert;
	std::cout << "Result multiplying matrix \t: \n" << nResult << std::endl;
	//apply conversion 
	nResult = mConvert.array() * nConvert.array();
	std::cout << "After doing conversion from matrices to array\n" << nResult << std::endl;
	//apply other method -> cons.cwiseProduct()
	nResult = mConvert.cwiseProduct(mConvert);
	std::cout << "Usign cwiseProduct method \n" <<nResult<< std::endl;
	//adding scalar by cwise operation 
	nResult = mConvert.array() + 4;
	std::cout << "adding scalar +4 by conversion \n" << nResult.array() + 4 << std::endl;
	
	std::cout << "Test conversion array to matrix" << std::endl;
	Eigen::MatrixXf mCon(2, 2 ), nCon(2, 2), nRes(2, 2);
	mCon << 1, 2,
			3, 4;
	nCon << 5, 6,
			7, 8;
	nRes = (mCon.array() + 4).matrix() * mCon;
	std::cout << "1. After apply combination \n" << nRes << std::endl;
	nRes = (mCon.array() * nCon.array()).matrix() * mCon;
	std::cout << "2. After apply combination \n" << nRes << std::endl;
	
	//note : this is only apply as rvalue, i.e it was only read form 
	std::cout << "Using Block Operations" << std::endl;
	Eigen::MatrixXf mBlock(4, 4);
	mBlock << 1, 2, 3, 4,
			5, 6, 7, 8,
			9, 10, 11, 12,
			13, 14, 15, 16;
	std::cout << "Original Matrices\n" << mBlock << std::endl;
	std::cout << "Test , show blow in the middle\n" << mBlock.block<2, 2>(1, 1) << std::endl;
	for (size_t i = 1; i <= 3; ++i) {
		std::cout << "Block of size " << i << " x " << i << std::endl;
		std::cout << mBlock.block(0, 0, i, i)<<std::endl; // starting at 0,0 and size is correspond to  variable i 
	}
	
	//case : apply lvalues , i.e can assign to a block 
	Eigen::Array22f SecDimen;
	Eigen::Array44f fourTimesFour = Eigen::Array44f::Constant(0.6);
	std::cout << "Matrix m that copy as a block the matrix four \n" << m << std::endl;
	std::cout << "Here is the current array \n" << fourTimesFour << std::endl;
	//here is the example of applying lvalues
	fourTimesFour.block<2, 2>(1, 1) = m;
	std::cout << "After copy to the central 2x2 block \n" << fourTimesFour<< std::endl;
	//another block
	fourTimesFour.block(0, 0, 2, 3) = fourTimesFour.block(2, 1, 2, 3);
	std::cout << "Here is now a with bottom -right 2x3  block copied into  top-left  2x3 block  \n" << fourTimesFour << std::endl;


	return 0;
}
