/*
 *
 *                   _/_/_/    _/_/   _/    _/ _/_/_/    _/_/
 *                  _/   _/ _/    _/ _/_/  _/ _/   _/ _/    _/
 *                 _/_/_/  _/_/_/_/ _/  _/_/ _/   _/ _/_/_/_/
 *                _/      _/    _/ _/    _/ _/   _/ _/    _/
 *               _/      _/    _/ _/    _/ _/_/_/  _/    _/
 *
 *             ***********************************************
 *                              PandA Project
 *                     URL: http://panda.dei.polimi.it
 *                       Politecnico di Milano - DEIB
 *                        System Architectures Group
 *             ***********************************************
 *              Copyright (c) 2015-2017 Politecnico di Milano
 *
 *   This file is part of the PandA framework.
 *
 *   The PandA framework is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
*/
/**
 * @file asn_type.cpp
 * @brief Data classes storing information for asn types
 *
 * @author Marco Lattuada <marco.lattuada@polimi.it>
 *
*/

///Header include
#include "asn_type.hpp"

///booost include
#include <boost/lexical_cast.hpp>

///utility includ
#include "exceptions.hpp"

AsnType::AsnType(const AsnType_Kind _kind) :
   kind(_kind)
{}

AsnType::~AsnType()
{}

AsnType_Kind AsnType::GetKind()
{
   return kind;
}

BooleanAsnType::BooleanAsnType() :
   AsnType(AsnType_Kind::BOOLEAN)
{}

ChoiceAsnType::ChoiceAsnType(const std::list<std::pair<std::string, AsnTypeRef> > &_element_type_list) :
   AsnType(AsnType_Kind::CHOICE),
   element_type_list(_element_type_list)
{}

EnumeratedAsnType::EnumeratedAsnType(const std::list<std::pair<std::string, unsigned int> >& _named_number_list) :
   AsnType(AsnType_Kind::ENUMERATED),
   named_number_list(_named_number_list)
{}

IntegerAsnType::IntegerAsnType() :
   AsnType(AsnType_Kind::INTEGER)
{}

OctetStringAsnType::OctetStringAsnType(const std::string&_size) :
   AsnType(AsnType_Kind::OCTET_STRING)
{
   THROW_ASSERT(_size.find("SIZE") != std::string::npos, _size);
   THROW_ASSERT(_size.find("(") != std::string::npos, _size);
   THROW_ASSERT(_size.find(")") != std::string::npos, _size);
   const auto temp = _size.substr(_size.find("(")+1);
   const auto temp2 = temp.substr(0, temp.find(")"));
   size = boost::lexical_cast<size_t>(temp2);
}

OctetStringAsnType::~OctetStringAsnType()
{}

RealAsnType::RealAsnType() :
   AsnType(AsnType_Kind::REAL)
{}

RedefineAsnType::RedefineAsnType(const std::string&_name) :
   AsnType(AsnType_Kind::REDEFINE),
   name(_name)
{}

SequenceAsnType::SequenceAsnType(const std::list<std::pair<std::string, AsnTypeRef> > &_fields) :
   AsnType(AsnType_Kind::SEQUENCE),
   fields(_fields) 
{}

SequenceOfAsnType::SequenceOfAsnType(const std::string&_element, const std::string&_size):
   AsnType(AsnType_Kind::SEQUENCEOF),
   element(_element)
{
   THROW_ASSERT(_size.find("SIZE") != std::string::npos, _size);
   THROW_ASSERT(_size.find("(") != std::string::npos, _size);
   THROW_ASSERT(_size.find(")") != std::string::npos, _size);
   const auto temp = _size.substr(_size.find("(")+1);
   const auto temp2 = temp.substr(0, temp.find(")"));
   size = boost::lexical_cast<size_t>(temp2);
}

SetAsnType::SetAsnType(const std::list<std::pair<std::string, AsnTypeRef> > &_fields) :
   AsnType(AsnType_Kind::SET),
   fields(_fields)
{}


SetOfAsnType::SetOfAsnType(const std::string&_element, const std::string&_size):
   AsnType(AsnType_Kind::SETOF),
   element(_element),
   size(boost::lexical_cast<size_t>(_size))
{}

