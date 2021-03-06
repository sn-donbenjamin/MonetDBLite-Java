/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0.  If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 2008-2017 MonetDB B.V.
 */

#include "nl_cwi_monetdb_embedded_env_MonetDBEmbeddedPreparedStatement.h"

#include "monetdb_config.h"
#include "embedded.h"
#include "javaids.h"
#include "jresulset.h"

JNIEXPORT void JNICALL Java_nl_cwi_monetdb_embedded_env_MonetDBEmbeddedPreparedStatement_freePreparedStatement
	(JNIEnv *env, jobject preparedStatement, jlong connectionPointer, jlong prepareStatementID) {
	char *err = NULL;
	(void) env;
	(void) preparedStatement;

	if((err = monetdb_clear_prepare((monetdb_connection) connectionPointer, (size_t) prepareStatementID)) != MAL_SUCCEED) {
		(*env)->ThrowNew(env, getMonetDBEmbeddedExceptionClassID(), err);
		GDKfree(err);
	}
}
