//
//  ZHCollectionViewDataSource.h
//  Pods
//
//  Created by 张行 on 2018/2/6.
//
//

#import <UIKit/UIKit.h>
#import "ZHCollectionViewGroup.h"
#import "ZHCollectionViewGroup.h"
#import "ZHCollectionViewCell.h"
#import "ZHAutoConfigurationCollectionViewDelegate.h"
#import "ZHCollectionViewBaseModel.h"
#import "ZHCollectionViewHeaderFooter.h"

/**
 添加分组的回调
 
 @param group 创建的分组对象
 */
typedef void(^ZHCollectionViewDataSourceAddGroupCompletionHandle)(ZHCollectionViewGroup *group);

/**
 自定义高度的回调
 
 @return 自定义算法返回的高度
 */
typedef CGFloat (^ZHCollectionViewDataSourceCustomHeightCompletionHandle)(ZHCollectionViewBaseModel *model);

/**
 进行 UICollectionView 进行数据托管的数据源
 */
@interface ZHCollectionViewDataSource : NSObject

/**
 自动配置 UICollectionView 的 DataSource 和 Delegate 默认为 YES
 */
@property (nonatomic, assign, getter=isAutoConfigurationCollectionViewDelegate) BOOL autoConfigurationCollectionViewDelegate;

/**
 唯一的初始化ZHCollectionViewDataSource
 
 @param CollectionView 托管的 UICollectionView 的对象 必须存在
 @return ZHCollectionViewDataSource的对象
 */
- (instancetype)initWithCollectionView:(UICollectionView *)CollectionView;

/**
 添加一个分组
 
 @param completionHandle 返回新注册的分组对象 可以进行配置
 */
- (void)addGroupWithCompletionHandle:(ZHCollectionViewDataSourceAddGroupCompletionHandle)completionHandle;

/**
 进行刷新 UICollectionView
 */
- (void)reloadCollectionViewData;

/**
 获取分组Cell的个数 如果autoConfigurationCollectionViewDelegate = YES 此方法不用调用
 
 @param dataSource ZHCollectionViewDataSource数据源
 @param section 所在组索引
 @return 分组 Cell 的个数
 */
+ (NSInteger)numberOfRowsInSectionWithDataSource:(ZHCollectionViewDataSource *)dataSource section:(NSInteger)section;

/**
 获取对应索引的UICollectionViewCell 如果autoConfigurationCollectionViewDelegate = YES 此方法不用调用
 
 @param dataSource ZHCollectionViewDataSource数据源
 @param indexPath 所在的索引
 @return UICollectionViewCell
 */
+ (UICollectionViewCell *)cellForRowAtWithDataSource:(ZHCollectionViewDataSource *)dataSource indexPath:(NSIndexPath *)indexPath;

/**
 获取分组的个数 如果autoConfigurationCollectionViewDelegate = YES 此方法不用调用
 
 @param dataSource ZHCollectionViewDataSource的数据源
 @return 分组的个数
 */
+ (NSInteger)numberOfSectionsWithDataSource:(ZHCollectionViewDataSource *)dataSource;

/**
 获取Cell 所在索引的高度 如果autoConfigurationCollectionViewDelegate = YES 此方法不用调用
 
 @param dataSource ZHCollectionViewDataSource数据源
 @param indexPath 索引
 @param customHeightCompletionHandle 自定义高度回调 实现 ZHCollectionViewCell 属性 cellHeight 无效
 @return  Cell 的高度
 */
+ (CGFloat)heightForRowAtDataSource:(ZHCollectionViewDataSource *)dataSource indexPath:(NSIndexPath *)indexPath customHeightCompletionHandle:(ZHCollectionViewDataSourceCustomHeightCompletionHandle)customHeightCompletionHandle;

/**
 点击 Cell 的回调
 
 @param dataSource ZHCollectionViewDataSource数据源
 @param indexPath 点击的索引
 */
+ (void)didSelectRowAtWithDataSource:(ZHCollectionViewDataSource *)dataSource indexPath:(NSIndexPath *)indexPath;

/**
 获取 Header 的高度
 
 @param dataSource ZHCollectionViewDataSource数据源
 @param section 分组索引
 @param customHeightCompletionHandle 自定义高度回调
 @return 分组 Header 高度
 */
+ (CGFloat)heightForHeaderInSectionWithDataSource:(ZHCollectionViewDataSource *)dataSource section:(NSInteger)section customHeightCompletionHandle:(ZHCollectionViewDataSourceCustomHeightCompletionHandle)customHeightCompletionHandle;

/**
 获取 Footer 的高度
 
 @param dataSource ZHCollectionViewDataSource数据源
 @param section 分组索引
 @param customHeightCompletionHandle 自定义高度回调
 @return 分组 Footer 高度
 */
+ (CGFloat)heightForFooterInSectionWithDataSource:(ZHCollectionViewDataSource *)dataSource section:(NSInteger)section customHeightCompletionHandle:(ZHCollectionViewDataSourceCustomHeightCompletionHandle)customHeightCompletionHandle;

/**
 获取Header
 
 @param dataSource ZHCollectionViewDataSource数据源
 @param section 分组的索引
 @return 分组 Header 试图
 */
+ (UICollectionReusableView *)viewForHeaderInSectionWithDataSource:(ZHCollectionViewDataSource *)dataSource section:(NSInteger)section;
/**
 获取Footer
 
 @param dataSource ZHCollectionViewDataSource数据源
 @param section 分组的索引
 @return 分组 Footer 试图
 */
+ (UICollectionReusableView *)viewForFooterInSectionWithDataSource:(ZHCollectionViewDataSource *)dataSource section:(NSInteger)section;

/**
 清空之前数据
 */
- (void)clearData;

+ (NSIndexPath *)indexPathWithDataSource:(ZHCollectionViewDataSource *)dataSource indexPath:(NSIndexPath *)indexPath;

@end
