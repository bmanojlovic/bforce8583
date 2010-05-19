/*!	\file	
 MultiXWSServer.cpp : Defines the entry point for the console application.
*/

/*

MultiX Network Applications Development Toolkit.
Copyright (C) 2007, Moshe Shitrit, Mitug Distributed Systems Ltd., All Rights Reserved.

This file is part of MultiX.

MultiX is free software; you can redistribute it and/or modify it under the terms of the 
GNU General Public License as published by the Free Software Foundation; 
either version 2 of the License, or (at your option) any later version. 

MultiX is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program;
if not, write to the 
Free Software Foundation, Inc., 
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
--------------------------------------------------------------------------------
Author contact information: 
msr@mitug.co.il
--------------------------------------------------------------------------------

*/


#include "MultiXWSServer.h"
#include	"MultiXWSServerApp.h"

/*!
	the main function is used just to create the main CMultiXWSServerApp object,
	start it and wait for it finish.
*/
int main(int Argc, char* Argv[])
{
	CMultiXWSServerApp	App(Argc,Argv,"MultiXWSServer Class");
	App.Start();
	App.WaitEnd();

	return	0;
}
