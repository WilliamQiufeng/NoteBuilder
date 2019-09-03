//
// Created by Qiufeng54321 on 2019-09-02.
// Copyright (C) 2019  Qiufeng54321
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef NOTEBUILDER_HEADER_HPP
#define NOTEBUILDER_HEADER_HPP

#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <exception>

#define DEFINE_TEMPLATE_CLASS_INIT_FOR(cls, type) \
    template class cls<type>;
#define DEFINE_TEMPLATE_CLASS_GENERIC_INIT_FOR(cls, type) \
    template class cls<GenericTag<type>>;

#define DEFINE_TEMPLATE_INIT_FOR(cls) \
    DEFINE_TEMPLATE_CLASS_INIT_FOR(cls,int)\
    DEFINE_TEMPLATE_CLASS_INIT_FOR(cls,long)\
    DEFINE_TEMPLATE_CLASS_INIT_FOR(cls,float)\
    DEFINE_TEMPLATE_CLASS_INIT_FOR(cls,double)\
    DEFINE_TEMPLATE_CLASS_INIT_FOR(cls,bool)\
    DEFINE_TEMPLATE_CLASS_INIT_FOR(cls,short);
#define DEFINE_TEMPLATE_GENERIC_INIT_FOR(cls) \
    DEFINE_TEMPLATE_CLASS_GENERIC_INIT_FOR(cls,int)\
    DEFINE_TEMPLATE_CLASS_GENERIC_INIT_FOR(cls,long)\
    DEFINE_TEMPLATE_CLASS_GENERIC_INIT_FOR(cls,float)\
    DEFINE_TEMPLATE_CLASS_GENERIC_INIT_FOR(cls,double)\
    DEFINE_TEMPLATE_CLASS_GENERIC_INIT_FOR(cls,bool)\
    DEFINE_TEMPLATE_CLASS_GENERIC_INIT_FOR(cls,short);
#define DEFINE_LIST_CLASS_MEMBERS(cls)\
    explicit cls();\
    typedef GenericTag<T> generic_type;\
    typedef std::vector<generic_type*> type;\
    type value;\
    void insert(std::size_t index, typename cls<T>::generic_type* val);\
    typename cls<T>::generic_type* get(std::size_t index);\
    void add(typename cls<T>::generic_type* val);\
    static std::string getType();\
    void toString(std::ostringstream &os) override;

#endif //NOTEBUILDER_HEADER_HPP
