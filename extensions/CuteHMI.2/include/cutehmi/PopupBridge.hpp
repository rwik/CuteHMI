#ifndef H_MODULES_CUTEHMI_u_1_INCLUDE_CUTEHMI_POPUPBRIDGE_HPP
#define H_MODULES_CUTEHMI_u_1_INCLUDE_CUTEHMI_POPUPBRIDGE_HPP

#include "internal/common.hpp"
#include "Prompt.hpp"

#include <QObject>
#include <QMutexLocker>

namespace cutehmi {

/**
 * %Popup bridge.
 */
class CUTEHMI_API PopupBridge:
	public QObject
{
	Q_OBJECT

	public:
		explicit PopupBridge(QObject * parent = nullptr);

		/**
		 * Advertise prompt.
		 * @param prompt_l prompt to advertise. Parameter will be used locally by this function.
		 * It's passed by a pointer instead of a reference for easier integration with QML.
		 *
		 * @threadsafe
		 */
		Q_INVOKABLE void advertise(Prompt * prompt_l);

		Q_INVOKABLE void resetAdvertiser(QObject * advertiser);

	signals:
		void promptRequested(QVariant);

	private:
		struct Members
		{
			QMutex requestMutex {};
			QObject * advertiser {nullptr};
		};

		MPtr<Members> m;
};

}

#endif

//(c)MP: Copyright © 2018, Michal Policht. All rights reserved.
//(c)MP: This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
