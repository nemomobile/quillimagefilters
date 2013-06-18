/****************************************************************************
**
** Copyright (C) 2009-11 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Pekka Marjola <pekka.marjola@nokia.com>
**
** This file is part of the Quill Image Filters package.
**
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
****************************************************************************/

#include "../base/quillimagefilter.h"
#include "../base/quillimagefilterinterface.h"
#include "greyscale.h"
#include "sepia.h"
#include "oldcolorphoto.h"
#include "crossprocessing.h"
#include "vintageplugin.h"

VintagePlugin::VintagePlugin()
{
}

QuillImageFilterImplementation *VintagePlugin::create(const QString &name)
{
    if (name == QuillImageFilter::Name_Greyscale)
        return new Greyscale;
    else if (name == QuillImageFilter::Name_Sepia)
        return new Sepia;
    else if (name == QuillImageFilter::Name_OldColorPhoto)
        return new OldColorPhoto;
    else if (name == QuillImageFilter::Name_CrossProcessing)
        return new CrossProcessing;
    else
        return 0;
}

const QStringList VintagePlugin::name() const
{
    QStringList list;
    list << QuillImageFilter::Name_Greyscale
         << QuillImageFilter::Name_Sepia
         << QuillImageFilter::Name_OldColorPhoto
         << QuillImageFilter::Name_CrossProcessing;
    return list;
}

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
Q_EXPORT_PLUGIN2(vintage, VintagePlugin)
#endif
