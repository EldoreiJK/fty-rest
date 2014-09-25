/*
Copyright (C) 2014 Eaton
 
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*! \file client.h
    \brief Basic class for manipulating with the database objects stored 
    in tha table t_bios_client.

    \author Alena Chernikava <alenachernikava@eaton.com>
*/  
#ifndef CLIENT_H_
#define CLIENT_H_

#include "databaseobject.h"

namespace utils{

class Client: public DataBaseObject
{
    public:

        /**
         * \brief Creates a new object and specifies a connection.
         *
         * Creates a new object for the specified url in state OS_NEW
         */
        Client(std::string url);

        /**
         * \brief Selects from the DB a client by its name
         *
         * Selects from DB client by name.
         *
         * \return A number of rows selected.
         */
        unsigned int selectByName(std::string name);

        /**
         * \brief Returns client's name
         */
        std::string getName();

        /**
         * \brief Sets a new name for the object.
         *
         * If state is OS_DELETED then do nothing
         * If newname = oldname then do nothing
         * If state is OS_SELECTED and newname != oldname
         *  than state is changed to OS_UPDATED.
         *
         * \param name - new name of the client
         */    
        void setName(std::string name);
        
        /**
         * \brief Selects from DB a client by ID. Rewrites object.
         *
         * If client was found:
         * -selects exactly one row
         * -state changed to OS_SELECTED
         *
         * If client was not found:
         * -selects nothing
         * -everything remains the same
         *  
         * \param id of row in database
         *  
         * \return A number of rows selected
         */
        unsigned int selectById(unsigned int id);

        ~Client();
        
        /**
         * \brief Selects an Id by name in the DB specified by url
         *
         * Selects an Id by name in the DB specified by url
         * 
         * \param url - specifies database
         * \param name - name of the client
         * 
         * \return an ID or -1 if nothing was found
         */
        static int selectId(std::string url, std::string name);

        /**
         * \brief Returns all fields as string
         */
        std::string toString();
        
        /**
         * \brief Returns an object to OS_NEW state with initial parameters
         */
        void clear();

    protected:
        
        /**
         * \brief Internal method for insert 
         *
         * \return A Number of rows affected 
         */
        unsigned int db_insert();
        
        /**
         * \brief Internal method for update
         *          
         * \return A Number of rows affected
         */
        unsigned int db_update();

        /**
         * \brief Internal method for delete
         *          
         * \return A Number of rows affected
         */
        unsigned int db_delete();
        
        /**
         * \brief Internal method for check before insert or update
         */
        bool check();

    private:
    
        /**
         * \brief Returns private fields of this object to initial state
         */
        void clear_this();
        
        /**
         * \brief A name of the client
         */
        std::string _name;

};  // end of the class

}   // end of namespace

#endif //CLIENT_H_
