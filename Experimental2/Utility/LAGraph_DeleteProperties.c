//------------------------------------------------------------------------------
// LAGraph_DeleteProperties: deletes the cached properties of a graph
//------------------------------------------------------------------------------

// LAGraph, (c) 2021 by The LAGraph Contributors, All Rights Reserved.
// SPDX-License-Identifier: BSD-2-Clause

//------------------------------------------------------------------------------

#include "LAGraph_Internal.h"

int LAGraph_DeleteProperties    // returns 0 if successful, -1 if failure
(
    LAGraph_Graph G,        // G stays valid, only cached properties are freed
    char *msg
)
{

    //--------------------------------------------------------------------------
    // check inputs
    //--------------------------------------------------------------------------

    LAGraph_CLEAR_MSG ;
    if (G == NULL)
    { 
        // success: nothing to do
        return (0) ;
    }

    //--------------------------------------------------------------------------
    // free all cached properties of the graph
    //--------------------------------------------------------------------------

    GrB_TRY (GrB_free (&(G->AT))) ;
    GrB_TRY (GrB_free (&(G->rowdegree))) ;
    GrB_TRY (GrB_free (&(G->coldegree))) ;

    // success
    return (0) ;
}

