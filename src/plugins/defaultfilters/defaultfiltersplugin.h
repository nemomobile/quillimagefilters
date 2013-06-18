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

#ifndef _DEFAULTFILTERSPLUGIN_H_
#define _DEFAULTFILTERSPLUGIN_H_

#include "../base/quillimagefilter.h"
#include "../base/quillimagefilterinterface.h"
#include "loadfilter.h"
#include "overlay.h"
#include "savefilter.h"
#include "scalecrop.h"
#include "serialsaver.h"


class DefaultFiltersPlugin : public QObject,
    public QuillImageFilterInterface
{
    Q_OBJECT
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    Q_PLUGIN_METADATA(IID QUILL_IMAGE_FILTER_INTERFACE_ID FILE "defaultfilters.json")
#endif
    Q_INTERFACES(QuillImageFilterInterface)

public:
    DefaultFiltersPlugin();

    QuillImageFilterImplementation *create(const QString&);
    QuillImageFilterImplementation *create(QuillImageFilter::QuillFilterRole role);

    const QStringList name() const;

    const QList<QuillImageFilter::QuillFilterRole> role() const;

private:
    Q_DISABLE_COPY(DefaultFiltersPlugin);
};

/*!
  Cleans up resources used by the plugin. The plugin must be able of
  re-creating what it needs to work when the next time a filter is
  instantiated.
 */
Q_EXTERN_C Q_DECL_EXPORT void quillimagefilter_plugin_cleanup();

#endif
