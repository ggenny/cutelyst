/*
 * Copyright (C) 2017 Matthias Fehring <kontakt@buschmann23.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#ifndef CUTELYSTVALIDATORDIGITSBETWEEN_P_H
#define CUTELYSTVALIDATORDIGITSBETWEEN_P_H

#include "validatordigitsbetween.h"
#include "validatorrule_p.h"

namespace Cutelyst {
    
class ValidatorDigitsBetweenPrivate : public ValidatorRulePrivate
{
public:
    ValidatorDigitsBetweenPrivate(const QString &f, int mi, int ma, const QString &l, const QString &e) :
        ValidatorRulePrivate(f, l, e),
        min(mi),
        max(ma)
    {}

    int min;
    int max;
};
    
}

#endif //CUTELYSTVALIDATORDIGITSBETWEEN_P_H

