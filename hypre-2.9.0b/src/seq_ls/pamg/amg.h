/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision: 2.9 $
 ***********************************************************************EHEADER*/





#ifndef hypre_AMG_DATA_HEADER
#define hypre_AMG_DATA_HEADER

/*--------------------------------------------------------------------------
 * hypre_AMGData
 *--------------------------------------------------------------------------*/

typedef struct
{

   /* setup params */
   HYPRE_Int      max_levels;
   double   strong_threshold;
   double   A_trunc_factor;
   double   P_trunc_factor;
   HYPRE_Int      A_max_elmts;
   HYPRE_Int      P_max_elmts;
   HYPRE_Int      coarsen_type;
   HYPRE_Int      agg_coarsen_type;
   HYPRE_Int      interp_type;
   HYPRE_Int      agg_interp_type;
   HYPRE_Int      agg_levels;
   HYPRE_Int      num_relax_steps;  
   HYPRE_Int      num_jacs;
   HYPRE_Int use_block_flag;

   /* solve params */
   HYPRE_Int      max_iter;
   HYPRE_Int      cycle_type;    
   HYPRE_Int     *num_grid_sweeps;  
   HYPRE_Int     *grid_relax_type;   
   HYPRE_Int    **grid_relax_points; 
   double  *relax_weight;
   double   tol;
   /* problem data */
   hypre_CSRMatrix  *A;
   HYPRE_Int      num_variables;
   HYPRE_Int      num_functions;
   HYPRE_Int      num_points;
   HYPRE_Int     *dof_func;
   HYPRE_Int     *dof_point;
   HYPRE_Int     *point_dof_map;           

   /* data generated in the setup phase */
   hypre_CSRMatrix **A_array;
   hypre_BCSRMatrix **B_array;
   hypre_Vector    **F_array;
   hypre_Vector    **U_array;
   hypre_CSRMatrix **P_array;
   hypre_BCSRMatrix **PB_array;
   HYPRE_Int             **CF_marker_array;
   HYPRE_Int             **dof_func_array;
   HYPRE_Int             **dof_point_array;
   HYPRE_Int             **point_dof_map_array;
   HYPRE_Int               num_levels;
   HYPRE_Int      	    *schwarz_option;
   HYPRE_Int      	    *num_domains;
   HYPRE_Int     	   **i_domain_dof;
   HYPRE_Int     	   **j_domain_dof;
   double  	   **domain_matrixinverse;
   HYPRE_Int		     mode;

   /* data generated in the solve phase */
   hypre_Vector   *Vtemp;
   double   *vtmp;
   HYPRE_Int       cycle_op_count;                                                   

   /* output params */
   HYPRE_Int      ioutdat;
   char     log_file_name[256];

} hypre_AMGData;

/*--------------------------------------------------------------------------
 * Accessor functions for the hypre_AMGData structure
 *--------------------------------------------------------------------------*/

/* setup params */
		  		      
#define hypre_AMGDataMaxLevels(amg_data) ((amg_data)->max_levels)
#define hypre_AMGDataStrongThreshold(amg_data) ((amg_data)->strong_threshold)
#define hypre_AMGDataATruncFactor(amg_data) ((amg_data)->A_trunc_factor)
#define hypre_AMGDataPTruncFactor(amg_data) ((amg_data)->P_trunc_factor)
#define hypre_AMGDataAMaxElmts(amg_data) ((amg_data)->A_max_elmts)
#define hypre_AMGDataPMaxElmts(amg_data) ((amg_data)->P_max_elmts)
#define hypre_AMGDataCoarsenType(amg_data) ((amg_data)->coarsen_type)
#define hypre_AMGDataAggCoarsenType(amg_data) ((amg_data)->agg_coarsen_type)
#define hypre_AMGDataInterpType(amg_data) ((amg_data)->interp_type)
#define hypre_AMGDataAggInterpType(amg_data) ((amg_data)->agg_interp_type)
#define hypre_AMGDataAggLevels(amg_data) ((amg_data)->agg_levels)
#define hypre_AMGDataNumRelaxSteps(amg_data) ((amg_data)->num_relax_steps)
#define hypre_AMGDataNumJacs(amg_data) ((amg_data)->num_jacs)
#define hypre_AMGDataUseBlockFlag(amg_data) ((amg_data)->use_block_flag)
/* solve params */

#define hypre_AMGDataMaxIter(amg_data) ((amg_data)->max_iter)
#define hypre_AMGDataCycleType(amg_data) ((amg_data)->cycle_type)
#define hypre_AMGDataTol(amg_data) ((amg_data)->tol)
#define hypre_AMGDataNumGridSweeps(amg_data) ((amg_data)->num_grid_sweeps)
#define hypre_AMGDataGridRelaxType(amg_data) ((amg_data)->grid_relax_type)
#define hypre_AMGDataGridRelaxPoints(amg_data) ((amg_data)->grid_relax_points)
#define hypre_AMGDataRelaxWeight(amg_data) ((amg_data)->relax_weight)

/* problem data parameters */
#define  hypre_AMGDataNumVariables(amg_data)  ((amg_data)->num_variables)
#define hypre_AMGDataNumFunctions(amg_data) ((amg_data)->num_functions)
#define hypre_AMGDataNumPoints(amg_data) ((amg_data)->num_points)
#define hypre_AMGDataDofFunc(amg_data) ((amg_data)->dof_func)
#define hypre_AMGDataDofPoint(amg_data) ((amg_data)->dof_point)
#define hypre_AMGDataPointDofMap(amg_data) ((amg_data)->point_dof_map)

/* data generated by the setup phase */
#define hypre_AMGDataCFMarkerArray(amg_data) ((amg_data)-> CF_marker_array)
#define hypre_AMGDataAArray(amg_data) ((amg_data)->A_array)
#define hypre_AMGDataBArray(amg_data) ((amg_data)->B_array)
#define hypre_AMGDataFArray(amg_data) ((amg_data)->F_array)
#define hypre_AMGDataUArray(amg_data) ((amg_data)->U_array)
#define hypre_AMGDataPArray(amg_data) ((amg_data)->P_array)
#define hypre_AMGDataPArray(amg_data) ((amg_data)->P_array)
#define hypre_AMGDataPBArray(amg_data) ((amg_data)->PB_array)
#define hypre_AMGDataDofFuncArray(amg_data) ((amg_data)->dof_func_array) 
#define hypre_AMGDataDofPointArray(amg_data) ((amg_data)->dof_point_array) 
#define hypre_AMGDataPointDofMapArray(amg_data) ((amg_data)->point_dof_map_array)
#define hypre_AMGDataNumLevels(amg_data) ((amg_data)->num_levels)
#define hypre_AMGDataSchwarzOption(amg_data) ((amg_data)->schwarz_option)
#define hypre_AMGDataNumDomains(amg_data) ((amg_data)->num_domains)
#define hypre_AMGDataIDomainDof(amg_data) ((amg_data)->i_domain_dof)
#define hypre_AMGDataJDomainDof(amg_data) ((amg_data)->j_domain_dof)
#define hypre_AMGDataDomainMatrixInverse(amg_data) ((amg_data)->domain_matrixinverse)
#define hypre_AMGDataMode(amg_data) ((amg_data)->mode)

/* data generated in the solve phase */
#define hypre_AMGDataVtemp(amg_data) ((amg_data)->Vtemp)
#define hypre_AMGDataCycleOpCount(amg_data) ((amg_data)->cycle_op_count)

/* output parameters */
#define hypre_AMGDataIOutDat(amg_data) ((amg_data)->ioutdat)
#define hypre_AMGDataLogFileName(amg_data) ((amg_data)->log_file_name)

#endif



